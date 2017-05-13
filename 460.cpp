// 460. LFU Cache - https://leetcode.com/problems/lfu-cache

#include "bits/stdc++.h"

using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) {
        capacity_ = capacity;
    }
    
    // Get the value (will always be positive) of the key
    // if the key exists in the cache, otherwise return -1.
    int get(int key) {
        if (!key_to_vf.count(key)) {
            return -1;
        }
        int value = key_to_vf[key].first;
        update_freq(key);
        return value;
    }
    
    // Set or insert the value if the key is not already present.
    // When the cache reaches its capacity, it should invalidate
    // the least frequently used item before inserting a new item.
    // For the purpose of this problem, when there is a tie (i.e.,
    // two or more keys that have the same frequency), the least
    // recently used key would be evicted.
    void put(int key, int value) {
        if (!key_to_vf.count(key)) {
            if (capacity_ == (int)key_to_vf.size()) {
                if (capacity_ == 0) { return; }
                int key_to_delete = freq_to_ll[min_freq].back();
                freq_to_ll[min_freq].pop_back();
                key_to_it.erase(key_to_delete);
                key_to_vf.erase(key_to_delete);
            }
            int freq = 1;
            min_freq = freq;
            key_to_vf[key] = {value, freq};
            touch(key);
        } else {
            key_to_vf[key].first = value;
            update_freq(key);
        }
    }
    
    void update_freq(int key) {
        int freq = key_to_vf[key].second;
        
        auto it = key_to_it[key];
        freq_to_ll[freq].erase(it);
        
        if (min_freq == freq && freq_to_ll[freq].empty()) {
            min_freq += 1;
        }
        
        freq += 1;
        key_to_vf[key].second = freq;
        touch(key);
    }
    
    // Insert node to the front of the linked list
    void touch(int key) {
        int freq = key_to_vf[key].second;
        freq_to_ll[freq].push_front(key);
        key_to_it[key] = freq_to_ll[freq].begin();
    }
private:
    // key -> {value, freq}
    unordered_map<int, pair<int, int> > key_to_vf;
    
    // freq -> {LL}
    unordered_map<int, list<int>> freq_to_ll;
    
    // key -> {iterator of LL}
    unordered_map<int, list<int>::iterator> key_to_it;
    
    int capacity_;
    int min_freq = 0;
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

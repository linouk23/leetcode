// 380. Insert Delete GetRandom O(1) - https://leetcode.com/problems/insert-delete-getrandom-o1

#include "bits/stdc++.h"

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() { }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (val_to_index.count(val)) { return false; }
        vec.push_back(val);
        val_to_index[val] = (int)vec.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!val_to_index.count(val)) { return false; }
        
        int ind_to_delete = val_to_index[val];
        swap(vec[ind_to_delete], vec.back());
        val_to_index.erase(val);
        if (ind_to_delete != (int)vec.size() - 1) {
            val_to_index[vec[ind_to_delete]] = ind_to_delete;
        }
        vec.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, (int)vec.size() - 1);
        int random_index = dis(gen);
        return vec[random_index];
    }
private:
    vector<int> vec;
    unordered_map<int, int> val_to_index;
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

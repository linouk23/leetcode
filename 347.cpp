// 347. Top K Frequent Elements - https://leetcode.com/problems/top-k-frequent-elements

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashtable;
        for (const int & num : nums) {
            hashtable[num] += 1;
        }
        for (const auto & it : hashtable) {
            max_heap_.emplace(HeapVertex{it.first, it.second});
        }
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.emplace_back(max_heap_.top().value);
            max_heap_.pop();
        }
        return {result.rbegin(), result.rend()};
    }
private:
    struct HeapVertex {
        int value, freq;
        
        bool operator<(const HeapVertex& that) const {
            return freq < that.freq;
        }
    };
    priority_queue<HeapVertex> max_heap_;
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
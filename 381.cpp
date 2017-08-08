// 381. Insert Delete GetRandom O(1) - Duplicates allowed - https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool wasPresented = !m.count(val);
        
        int n = (int)nums.size();
        nums.emplace_back(val);
        m[val].insert(n);
        
        return wasPresented;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!m.count(val)) { return false; }
        int idx_val = *m[val].begin();
        m[val].erase(m[val].begin());
        if (m[val].empty()) {
            m.erase(val);
        }
        
        
        if ((int)nums.size() == 1) {
            nums.pop_back();
            return true;
        }
        
        // Swap elements [n - 1], [val_idx]
        int val_to_swap = nums.back();
        int idx_to_swap = (int)nums.size() - 1;
        nums.pop_back();
        m[val_to_swap].erase(idx_to_swap);
        
        nums[idx_val] = val_to_swap;
        m[val_to_swap].insert(idx_val);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int n = (int)nums.size();
        uniform_int_distribution<int> distribution(0, n - 1);
        int rand_idx = distribution(generator);
        return nums[rand_idx];
    }
private:
    //
    vector<int> nums;
    // (val, {idxs} in the nums)
    unordered_map<int, unordered_set<int>> m;
    default_random_engine generator;
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

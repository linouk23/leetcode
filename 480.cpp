// 480. Sliding Window Median - https://leetcode.com/problems/sliding-window-median

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

typedef long long ll;

// Trick: reuse iterators.
// https://discuss.leetcode.com/topic/74963/o-n-log-k-c-using-multiset-and-updating-middle-iterator
class Solution {
// private:
//     unordered_map<int, int> moves = {
//         {11, 0},
//         {12, 1},
//         {13, 1},
//         {23, 1},
//         {22, 1},
//         {21, 0},
//         {33, 0},
//         {32, -1},
//         {31, -1}
//     };
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<ll> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> medians;
        int idx = k;
        // {2, 3, 4, 10}
        //        ^
        //        |
        //       mid
        
        // {3, 4, 10}
        //     ^
        //     |
        //    mid
        while (true) {
            
            // Push the current median.
            medians.push_back((double(*mid) + double(*prev(mid, 1 - k % 2))) / 2.0);
            
            // If all done, return.
            if (idx == (int)nums.size()) { return medians; }
            
            window.insert(nums[idx]);
            if (nums[idx] < *mid) { mid--; }
            
            // Erase nums[idx - k].
            if (nums[idx - k] <= *mid) { mid++; }
            
            window.erase(window.lower_bound(nums[idx - k]));
            idx += 1;
        }
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

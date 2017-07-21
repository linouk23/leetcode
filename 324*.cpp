// 324. Wiggle Sort II - https://leetcode.com/problems/wiggle-sort-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Credits to
// https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing
// To get wiggle sort, you want to put the number in the following way such that
// (1) elements smaller than the 'median' are put into the last even slots
// (2) elements larger than the 'median' are put into the first odd slots
// (3) the medians are put into the remaining slots.

// Index :       0   1   2   3   4   5
// Small half:   M       S       S
// Large half:       L       L       M


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = (int)nums.size();
        
        // Find a median.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        // Index-rewiring.
        #define A(i) nums[(1+2*(i)) % (n|1)]
        
        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
    }
};


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

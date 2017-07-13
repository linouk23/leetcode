// 280. Wiggle Sort - https://leetcode.com/problems/wiggle-sort

#include "bits/stdc++.h"

using namespace std;

// The final sorted nums needs to satisfy two conditions:
// If i is odd, then nums[i] >= nums[i - 1];
// If i is even, then nums[i] <= nums[i - 1].

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = (int)nums.size();
        for (int idx = 1; idx < n; ++idx) {
            bool isOdd = idx % 2;
            bool isEven = !isOdd;
            if ((isOdd  && nums[idx] < nums[idx - 1]) ||
                (isEven && nums[idx] > nums[idx - 1])) {
                swap(nums[idx], nums[idx - 1]);
            }
        }
    }
};

//https://discuss.leetcode.com/topic/42605/my-explanations-of-the-best-voted-algo/2
//My explanation is recursive,
//suppose nums[0 .. i - 1] is wiggled, for position i:
//A)  if i is odd, we already have, nums[i - 2] >= nums[i - 1],
//A1) if nums[i - 1] <= nums[i], then we does not need
//    to do anything, its already wiggled.
//
//A2) if nums[i - 1] > nums[i], then we swap element at i - 1 and i.
//    Due to previous wiggled elements (nums[i - 2] >= nums[i - 1]),
//    we know after swap the sequence is ensured to be
//    nums[i - 2] > nums[i - 1] < nums[i], which is wiggled.
//
//similarly,
//
//B) if i is even, we already have, nums[i - 2] <= nums[i - 1],
//B1) if nums[i - 1] >= nums[i], pass
//B2) if nums[i - 1] < nums[i], after swap, we are sure to have wiggled nums[i - 2] < nums[i - 1] > nums[i].
//
//The same recursive solution applies to all the elements in the
//sequence, ensuring the algo success.

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

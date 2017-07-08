// 540. Single Element in a Sorted Array - https://leetcode.com/problems/single-element-in-a-sorted-array

#include "bits/stdc++.h"

using namespace std;

//         0 1 2 3 4 5 6 7 8
// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
// f()     0 0 1 1 1 1 1 1 1 -> find R from (L – the last 0, R – the 1st 1).
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int L = -1;
        int R = (int)nums.size();
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (M % 2) {
                if (nums[M] != nums[M - 1]) {
                    R = M;
                } else {
                    L = M;
                }
            } else {
                if (nums[M] != nums[M + 1]) {
                    R = M;
                } else {
                    L = M;
                }
            }
        }
        return nums[R];
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

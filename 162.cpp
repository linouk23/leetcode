// 162. Find Peak Element - https://leetcode.com/problems/find-peak-element

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = (int)nums.size();
        int L = 0;
        int R = n - 1;
        if (n == 1) { return 0; }
        // invariant: nums[L - 1] < nums[L] && nums[R] > nums[R + 1]
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (nums[M] < nums[M + 1]) {
                L = M + 1;
            } else {
                R = M;
            }
        }
        return (L == n - 1 || nums[L] > nums[R] ? L : R);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

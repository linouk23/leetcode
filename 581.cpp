// 581. Shortest Unsorted Continuous Subarray - https://leetcode.com/problems/shortest-unsorted-continuous-subarray

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int R = (int)nums.size() - 1;
        int L = 0;
        while (R >= 0 && sorted_nums[R] == nums[R]) {
            --R;
        }
        while (L < R && sorted_nums[L] == nums[L]) {
            ++L;
        }
        return R - L + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
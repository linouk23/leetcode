// 41. First Missing Positive - https://leetcode.com/problems/first-missing-positive

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = (int)nums.size();
        // We visit each number once, and each number will be put in its right place at most once.
        for (int idx = 0; idx < n; ++idx) {
            while (nums[idx] >= 1 && nums[idx] <= n && nums[idx] != nums[nums[idx] - 1]) {
                swap(nums[idx], nums[nums[idx] - 1]);
            }
        }
        for (int num = 1; num <= n; ++num) {
            if (nums[num - 1] != num) {
                return num;
            }
        }
        return n + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

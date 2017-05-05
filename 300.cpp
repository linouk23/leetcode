// 300. Longest Increasing Subsequence - https://leetcode.com/problems/longest-increasing-subsequence

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        nums.insert(nums.begin(), (int)-1e9);
        int n = (int)nums.size();
        vector<int> dp(n + 1, 0);
        for (int index = 1; index < n; ++index) {
            for (int end_to_continue = 0; end_to_continue < index; ++end_to_continue) {
                if (nums[index] <= nums[end_to_continue]) { continue; }
                dp[index] = max(dp[index], dp[end_to_continue] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

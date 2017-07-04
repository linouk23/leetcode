// 368. Largest Divisible Subset - https://leetcode.com/problems/largest-divisible-subset

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) { return {}; }
        int n = (int)nums.size();
        // Longest Increasing Subsequence (LIS).
        // Let dp[i] be the length of the LIS which is ending at element with index i.
        
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int NONE = -1;
        vector<int> parent(n, NONE);
        for (int cur = 0; cur < n; ++cur) {
            for (int prev = 0; prev < cur; ++prev) {
                if (nums[cur] % nums[prev] != 0) { continue; }
                if (dp[cur] < dp[prev] + 1) {
                    dp[cur] = dp[prev] + 1;
                    parent[cur] = prev;
                }
            }
        }
        int idx = int(max_element(dp.begin(), dp.end()) - dp.begin());
        vector<int> result;
        while(idx != NONE) {
            result.emplace_back(nums[idx]);
            idx = parent[idx];
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution sol;
    sol.isInterleave("a", "b", "ab");
    
    return 0;
}

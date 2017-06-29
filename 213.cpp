// 213. House Robber II - https://leetcode.com/problems/house-robber-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        if (nums.empty()) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        if (n <= 2) {
            return max(nums[0], nums[1]);
        }
        
        // [0, ..., n - 2]
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int idx = 2; idx <= n - 2; ++idx) {
            dp[idx] = max(dp[idx - 1], dp[idx - 2] + nums[idx]);
        }
        int best_if_rob_fst_house = dp[n - 2];
        // [1, ..., n - 1]
        dp[0] = 0;
        dp[1] = nums[1];
        for (int idx = 2; idx <= n - 1; ++idx) {
            dp[idx] = max(dp[idx - 1], dp[idx - 2] + nums[idx]);
        }
        int best_if_lock_fst_house = dp[n - 1];
        return max(best_if_rob_fst_house,
                   best_if_lock_fst_house);
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

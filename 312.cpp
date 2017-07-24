// 312. Burst Balloons - https://leetcode.com/problems/burst-balloons

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Idea: what balloon will be the last to burst?
// (assuming we do have all the other balloons, e.g.
// dp[2][2] = 3 * 1 * 5 = 15 for [3,1,5,8]

// M is idx of the last bursted balloon on [L, R] (a hurdle):
// neighbours_val = dp[L][M - 1] + dp[M + 1][R];
// [L, M - 1], [M + 1, R] balloons will be gone, so
// this should be:
// int burst_val = nums[L - 1] * nums[M] * nums[R + 1];
// dp[L][R] = max(dp[L][R], neighbours_val + burst_val);
class Solution {
public:
    int maxCoins(vector<int> nums) {
        int n = (int)nums.size();
        // Let dp[L][R] be the maximum amount of coins we
        // can collect by bursting the balloons wisely on segment [L, R]
        // Idea: what balloon will be the last to burst?
        // (assuming we do have all the other balloons, e.g.
        // dp[2][2] = 3 * 1 * 5 = 15 for [3,1,5,8]
        vector<vector<int>> dp(n + 10, vector<int> (n + 10, 0));
        // Insert fake ones into our nums:
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for (int len = 1; len <= n; ++len) {
            for (int L = 1; L <= n; ++L) {
                int R = L + len - 1;
                if (R > n) { break; }
                
                // We can burst any of [L, R] balloons in the end,
                // so let's choose the 'best last one'.
                // M is idx of the last bursted balloon on [L, R].
                for (int M = L; M <= R; ++M) {
                    // sum(best left val, best right val, what
                    // we'll get when burst happens) = val
                    // If the you burst balloon i you will
                    // get nums[left] * nums[i] * nums[right]
                    // coins. Here left and right are
                    // adjacent indices of i.
                    int neighbours_val = dp[L][M - 1] + dp[M + 1][R];
                    // int burst_val = nums[M] * nums[M - 1] * nums[M + 1];
                    // [L, M - 1], [M + 1, R] balloons will be gone, so
                    // this should be:
                    int burst_val = nums[L - 1] * nums[M] * nums[R + 1];
                    dp[L][R] = max(dp[L][R], neighbours_val + burst_val);
                }
            }
        }
        return dp[1][n];
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(167, sol.maxCoins({3,1,5,8}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

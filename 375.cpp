// 375. Guess Number Higher or Lower II - https://leetcode.com/problems/guess-number-higher-or-lower-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// https://discuss.leetcode.com/topic/68252/clarification-on-the-problem-description-problem-description-need-to-be-updated/8

// Idea: segment DP
// Why? Easy to calculate dp[L][L], dp[L][L + 1] and then brute the worst case
// using random middle point + max(dp[L][M - 1], dp[M + 1][R]).
// [L, L] -> 0
// [L, L + 1] -> worst case: L
// [L, L + 2] -> worst case: L + 1 (then get a response -> know the answer)
// min_k: k + max(dp[L][k - 1], dp[k + 1][R]), max because of worst case.
class Solution {
public:
    int getMoneyAmount(int n) {
        const int INF = (int)1e9;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, INF));
        for (int L = 1; L <= n; ++L) {
            dp[L][L] = 0;
        }
        for (int L = 1; L <= n - 1; ++L) {
            dp[L][L + 1] = L;
        }
        for (int L = 1; L <= n - 2; ++L) {
            dp[L][L + 2] = L + 1;
        }
        
        for (int len = 4; len <= n; ++len) {
            for (int L = 1; L + len - 1 <= n; ++L) {
                int R = L + len - 1;
                for (int k = L + 1; k + 1 <= R; ++k) {
                    // All of the segments of len 'k - 1' were already
                    // calculated.
                    int value = k + max(dp[L][k - 1], dp[k + 1][R]);
                    dp[L][R] = min(dp[L][R], value);
                }
            }
        }
        return dp[1][n];
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(16, sol.getMoneyAmount(10));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

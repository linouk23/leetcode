// 44. Wildcard Matching - https://leetcode.com/problems/wildcard-matching

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool isMatch(string f, string s) {
        int n = (int)f.length();
        int m = (int)s.length();
        vector<deque<bool>> dp(n + 1, deque<bool> (m + 1, false));
        dp[0][0] = true;
        for (int idx = 0; idx < m; ++idx) {
            if (s[idx] != '*') { break; }
            dp[0][idx + 1] = true;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // Indexes start from 0
                int si = i - 1, sj = j - 1;
                if (s[sj] == '*') {
                    // If star matches zero chars
                    dp[i][j] = dp[i][j - 1];
                    
                    // // If star matches 1 char
                    // dp[i][j] = dp[i][j] || dp[i - 1][j - 1];

                    // If star matches 1..k chars
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                    // If ba* matches bacd ->
                    //    ba* matches bacdqw
                    // Continue matching.
                } else {
                    // s[j] == '?' or is_letter
                    if (f[si] == s[sj] || s[sj] == '?') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[n][m];
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_TRUE(sol.isMatch("c", "*?*"));
    EXPECT_TRUE(sol.isMatch("aa", "*"));
    EXPECT_FALSE(sol.isMatch("aa","a"));
    EXPECT_TRUE(sol.isMatch("aa","aa"));
    EXPECT_FALSE(sol.isMatch("aaa","aa"));
    EXPECT_FALSE(sol.isMatch("aab", "c*a*b"));
    EXPECT_TRUE(sol.isMatch("aa", "a*"));
    EXPECT_TRUE(sol.isMatch("ab", "?*"));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

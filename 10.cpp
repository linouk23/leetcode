// 10. Regular Expression Matching - https://leetcode.com/problems/regular-expression-matching

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool isMatch(string f, string s) {
        int n = (int)f.length();
        int m = (int)s.length();
        vector<deque<bool>> dp(n + 1, deque<bool> (m + 1, false));
        // "" matches ""
        dp[0][0] = true;
        // "" matches "a*b*c*"
        for (int idx = 2; idx <= m; ++idx) {
            dp[0][idx] = dp[0][idx - 2] && s[idx - 1] == '*';
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int si = i - 1, sj = j - 1;
                if (f[si] == s[sj] || s[sj] == '.') {
                    // isM(aab, ab) -> isM(aa, a)
                    // isM(a., ab) -> isM(a, a)
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (s[sj] == '*') {
                    char repeated_ch = s[sj - 1];
                    // * -> 0 occurences of repeated_ch
                    // a, ab* -> OK
                    if (j >= 2) {
                        dp[i][j] = dp[i][j - 2];
                    }
                    if (f[si] == repeated_ch || repeated_ch == '.') {
                        // * -> 1...k occurences of repeated_ch
                        // isM(baaaaa, ba*) ->
                        // isM(baaaa , ba*) ->
                        // a is a part of a*,
                        // we won't break anything if we append 'a' to
                        // the string we want to match a*
                        // isM(b , ba*) OK -> isM(ba , ba*) OK ->
                        // isM(baa , ba*) OK -> isM(baaa , ba*) OK
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[n][m];
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_FALSE(sol.isMatch("a",".*..a*"));
    EXPECT_TRUE(sol.isMatch("aaa", "ab*ac*a"));
    EXPECT_FALSE(sol.isMatch("aa","a"));
    EXPECT_TRUE(sol.isMatch("aa","aa"));
    EXPECT_FALSE(sol.isMatch("aaa","aa"));
    EXPECT_TRUE(sol.isMatch("aa", "a*"));
    EXPECT_TRUE(sol.isMatch("aa", ".*"));
    EXPECT_TRUE(sol.isMatch("ab", ".*"));
    EXPECT_TRUE(sol.isMatch("aab", "c*a*b"));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

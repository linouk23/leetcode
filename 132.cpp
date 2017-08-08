// 132. Palindrome Partitioning II - https://leetcode.com/problems/palindrome-partitioning-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    vector<vector<bool>> dp;
    void run_is_palindrome_dp(const string &s) {
        int n = (int)s.length();
        dp.resize(n, vector<bool> (n, false));
        for (int idx = 0; idx < n; ++idx) {
            dp[idx][idx] = true;
        }
        for (int idx = 0; idx < n - 1; ++idx) {
            dp[idx][idx + 1] = (s[idx] == s[idx + 1]);
        }
        for (int len = 3; len <= n; ++len) {
            for (int start = 0; start + len - 1 < n; ++start) {
                int finish = start + len - 1;
                dp[start][finish] = (s[start] == s[finish]) ? dp[start + 1][finish - 1] : false;
            }
        }
    }
    bool is_palindrome(int L, int R) {
        return dp[L][R];
    }
public:
    int minCut(string s) {
        run_is_palindrome_dp(s);
        vector<int> result(s.length());
        iota(result.begin(), result.end(), 1);
        // Let result[idx] be the min cut for str[0:idx].
        int L = 0;
        for (int R = 0; R < s.length(); ++R) {
            if (is_palindrome(L, R)) { result[R] = 0; }
            else {
                // [L, M - 1] U [M, R]
                for (int M = 1; M <= R; ++M) {
                    if (is_palindrome(M, R)) {
                        result[R] = min(result[R],
                                        result[M - 1] + 1);
                    }
                }
            }
        }
        return result[s.length() - 1];
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(1, sol.minCut("aab"));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

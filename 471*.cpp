// 471. Encode String with Shortest Length - https://leetcode.com/problems/encode-string-with-shortest-length

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    string min_len(const string &s1, const string &s2) {
        if (s2.length() <= s1.length()) {
            return s2;
        }
        return s1;
    }
    vector<int> prefix_function(const string &s) {
        size_t n = s.length();
        vector<int> pi(n);
        for (int idx = 1; idx < n; ++idx) {
            int len = pi[idx - 1];
            while (len > 0 && s[idx] != s[len]) { len = pi[len - 1]; }
            if (s[idx] == s[len]) { ++len; }
            pi[idx] = len;
        }
        return pi;
    }
public:
    string encode(string s) {
        size_t n = s.length();
        // Let dp[i][j] be the answer for the s[i][j]
        // dp[i][j] = min_len(dp[i][j],
        //                    dp[i][k] + dp[k + 1][j])
        // Either represent s[i][j] as a pattern
        // or divide s[i][k] + s[k + 1][j] and 
        // take the answers for these segments:
        // dp[i][k] + dp[k + 1][j]
        // "2[2[abbb]c]" <- "abbbabbbcabbbabbbc"
        vector<vector<string>> dp(n, vector<string> (n, string(n, ' ')));
        for (size_t len = 1; len <= n; ++len) {
            for (size_t L = 0; L < n; ++L) {
                size_t R = L + len - 1;
                if (R >= n) { break; }
                dp[L][R] = s.substr(L, len);
                if (len <= 4) { continue; }
                // Try all results that we get after
                // dividing the strings into 2 and combine the
                // results of 2 substrings
                for (size_t M = L; M < R; ++M) {
                    dp[L][R] = min_len(dp[L][R], dp[L][M] + dp[M + 1][R]);
                }
                // Check if string can be represented
                // using repeated pattern.
                string substr = s.substr(L, len);
                // Finding the best compression using KMP
                // http://e-maxx.ru/algo/prefix_function
                auto pi = prefix_function(substr);
                // block_len = 2 for ABABAB
                size_t block_len = len - pi[len - 1];
                if (len % block_len) { continue; }
                // substr.substr(0, block_len) = dp[L][L + block_len - 1]
                // to get "2[2[abbb]c]" for "abbbabbbcabbbabbbc"
                string candidate = to_string(len / block_len)
                                   + "[" + dp[L][L + block_len - 1] + "]";
                dp[L][R] = min_len(dp[L][R], candidate);
            }
        }
        
        return dp[0][n - 1];
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ("aa", sol.encode("aa"));
    EXPECT_EQ("aaa", sol.encode("aaa"));
    EXPECT_EQ("5[a]", sol.encode("aaaaa"));
    EXPECT_EQ("10[a]", sol.encode("aaaaaaaaaa"));
    EXPECT_EQ("2[aabc]d", sol.encode("aabcaabcd"));
    EXPECT_EQ("2[2[abbb]c]", sol.encode("abbbabbbcabbbabbbc"));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

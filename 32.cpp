// 32. Longest Valid Parentheses - https://leetcode.com/problems/longest-valid-parentheses

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

/*
class Solution {
public:
    int longestValidParentheses(string s) {
        // L -> R pass
        int balance = 0; // open - closing
        // ( -> + 1
        // ) -> - 1
        int result = 0;
        int L = 0;
        int n = (int)s.length();
        for (int R = 0; R < n; ++R) {
            // Reset counters.
            if (balance < 0) {
                L = R;
                balance = 0;
            }
            
            if (s[R] == '(') {
                ++balance;
            } else {
                --balance;
            }
            
            if (balance == 0) {
                result = max(result, R - L + 1);
            }
        }
        // R -> L pass
        // Think about (()
        int R = n - 1;
        balance = 0;
        for (int L = n - 1; L >= 0; --L) {
            if (balance < 0) {
                R = L;
                balance = 0;
            }
            
            if (s[L] == ')') {
                ++balance;
            } else {
                --balance;
            }
            
            if (balance == 0) {
                result = max(result, R - L + 1);
            }
        }
        return result;
    }
};
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) { return 0; }
        int n = (int)s.length();
        // Let dp[i] be the length of the LTS which is ending at element with index i.
        vector<int> dp(n, 0);
        for (int idx = 1; idx < n; ++idx) {
            // Seq cannot be closed with '(' in the end.
            if (s[idx] != ')') { continue; }
            
            // )(()) -> check if we can increase dp[3]
            // 012345
            // -> find matching opening bracket before dp[3] seq
            int len_of_valid_seq = dp[idx - 1];
            int pos_right_before = idx - len_of_valid_seq - 1;
            if (pos_right_before < 0) { continue; }
            if (s[pos_right_before] != '(') { continue; }
            dp[idx] = dp[idx - 1] + 2;
            // )(())( , dp[3] = 2, dp[4] = dp[3] + s[1] + s[4] = 4
            // 012345
            pos_right_before -= 1;
            if (pos_right_before < 0) { continue; }
            // Overkill:
            // We'll have dp[idx] == 0 for s[idx] == '(' anyway.
            if (s[pos_right_before] != ')') { continue; }
            // ()() -> 2 + 2 = 4
            dp[idx] += dp[pos_right_before];
            
            // ()()()(())())
            // 020406002?
            // ? -> (()) -> find opening bracket and then plus***
            // prev valid sequence, so we'll get 12 instead of 4
        }
        return *max_element(dp.begin(), dp.end());
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(2, sol.longestValidParentheses("(()"));
    EXPECT_EQ(4, sol.longestValidParentheses(")()())"));
    EXPECT_EQ(12, sol.longestValidParentheses("()()()(())())"));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

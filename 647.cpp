// 647. Palindromic Substrings - https://leetcode.com/problems/palindromic-substrings

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    vector<deque<bool>> dp;
    void run_is_palindrome_dp(const string &s) {
        int n = (int)s.length();
        dp.resize(n, deque<bool> (n, false));
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
    int countSubstrings(string s) {
        int result = 0;
        run_is_palindrome_dp(s);
        for (int L = 0; L < s.length(); ++L) {
            for (int R = L; R < s.length(); ++R) {
                if (is_palindrome(L, R)) {
                    result += 1;
                }
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

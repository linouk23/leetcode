// 131. Palindrome Partitioning - https://leetcode.com/problems/palindrome-partitioning

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Trick: store vector<string> path_so_far.
class Solution {
private:
    vector<vector<string>> result;
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
    bool is_palindrome(const string &str, int L, int R) {
        return dp[L][R];
//        for (int idx = 0; idx < (R - L + 1) / 2; ++idx) {
//            if (str[L + idx] != str[R - idx]) {
//                return false;
//            }
//        }
//        return true;
    }
    void helper(const string &str, int start, int R,
                vector<string> path_so_far) {
        if (start == R + 1) {
            result.emplace_back(path_so_far);
        }
        
        for (int finish = start; finish <= R; ++finish) {
            if (!is_palindrome(str, start, finish)) { continue; }
            int len = finish - start + 1;
            path_so_far.emplace_back(str.substr(start, len));
            // str[start:finish] is palindrome -> continue search
            // from finish + 1;
            helper(str, finish + 1, R, path_so_far);
            path_so_far.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        run_is_palindrome_dp(s);
        helper(s, 0, (int)s.length() - 1, {});
        return result;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

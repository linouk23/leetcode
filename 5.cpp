// 5. Longest Palindromic Substring - https://leetcode.com/problems/longest-palindromic-substring

#include "bits/stdc++.h"

using namespace std;

class Solution {
    vector<deque<bool> > dp;
public:
    string longestPalindrome(string str) {
        int n = (int)str.length();
        dp.resize(n, deque<bool> (n, true));
        // L == R -> true
        // L == R + 1 -> true
        
        for (int len = 2; len <= n; ++len) {
            for (int L = 0; L + len - 1 < n; ++L) {
                int R = L + len - 1;
                if (str[L] != str[R]) {
                    dp[L][R] = false;
                } else {
                    dp[L][R] = dp[L + 1][R - 1];
                }
            }
        }
        
        for (int len = n; len > 1; --len) {
            for (int L = 0; L + len - 1 < n; ++L) {
                int R = L + len - 1;
                if (!dp[L][R]) { continue; }
                return str.substr(L, len);
            }
        }
        return str.substr(0, 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

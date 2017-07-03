// 516. Longest Palindromic Subsequence - https://leetcode.com/problems/longest-palindromic-subsequence

#include "bits/stdc++.h"

using namespace std;

const int INF = (int)1e9;

class Solution {
private:
    map<pair<int, int>, int> dp;
    int f(const string &str, int L, int R) {
        if (L == R)     { return 1; }
        if (L == R + 1) { return 0; }
        
        if (dp.count({L, R})) { return dp[{L, R}]; }
        int result = -INF;
        if (str[L] == str[R]) {
            result = max({
                result,
                f(str, L + 1, R - 1) + 2
            });
        } else {
            result = max({
                result,
                f(str, L + 1, R),
                f(str, L, R - 1),
            });
        }
        dp[{L, R}] = result;
        return dp[{L, R}];
    }
public:
    int longestPalindromeSubseq(string s) {
        return f(s, 0, int(s.length() - 1));
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

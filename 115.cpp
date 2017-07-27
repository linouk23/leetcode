// 115. Distinct Subsequences - https://leetcode.com/problems/distinct-subsequences

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = (int)t.length(), n = (int)s.length();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int idx = 0; idx <= n; ++idx) { dp[0][idx] = 1; }
        for (int idx1 = 1; idx1 <= n; ++idx1) {
            for (int idx2 = 1; idx2 <= m; ++idx2) {
                int cost = (t[idx2 - 1] == s[idx1 - 1] ? dp[idx2 - 1][idx1 - 1] : 0);
                dp[idx2][idx1] = dp[idx2][idx1 - 1] + cost;
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

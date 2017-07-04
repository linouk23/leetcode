// 583. Delete Operation for Two Strings - https://leetcode.com/problems/delete-operation-for-two-strings

#include "bits/stdc++.h"

using namespace std;

// 1 - LCS
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = (int)word1.length();
        int m = (int)word2.length();
        vector<vector<int> > dp(n + 1, vector<int> (m + 1));
        for (int col = 0; col <= m; ++col) {
            dp[0][col] = 0;
        }
        for (int row = 1; row <= n; ++row) {
            dp[row][0] = 0;
        }
        for (int row = 1; row <= n; ++row) {
            for (int col = 1; col <= m; ++col) {
                if (word1[row - 1] == word2[col - 1]) {
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                } else {
                    dp[row][col] = max(dp[row - 1][col],
                                       dp[row][col - 1]);
                }
            }
        }
        return n + m - 2 * dp[n][m];
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

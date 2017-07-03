// 583. Delete Operation for Two Strings - https://leetcode.com/problems/delete-operation-for-two-strings

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = (int)word1.length();
        int m = (int)word2.length();
        vector<vector<int> > dp(n + 1, vector<int> (m + 1));
        iota(dp[0].begin(), dp[0].end(), 0);
        for (int row = 1; row <= n; ++row) {
            dp[row][0] = row;
        }
        for (int row = 1; row <= n; ++row) {
            for (int col = 1; col <= m; ++col) {
                if (word1[row - 1] == word2[col - 1]) {
                    dp[row][col] = dp[row - 1][col - 1];
                } else {
                    dp[row][col] = min(dp[row - 1][col] + 1,
                                       dp[row][col - 1] + 1);
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

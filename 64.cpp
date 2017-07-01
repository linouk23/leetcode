// 64. Minimum Path Sum - https://leetcode.com/problems/minimum-path-sum

#include "bits/stdc++.h"

using namespace std;

const int INF = (int)1e9;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        
        vector<vector<int> > dp(n, vector<int> (m, INF));
        
        dp[0][0] = grid[0][0];
        for (int row = 1; row < n; ++row) {
            dp[row][0] = dp[row - 1][0] + grid[row][0];
        }
        for (int col = 1; col < m; ++col) {
            dp[0][col] = dp[0][col - 1] + grid[0][col];
        }
        for (int row = 1; row < n; ++row) {
            for (int col = 1; col < m; ++col) {
                dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + grid[row][col];
            }
        }
        return dp[n - 1][m - 1];
    }
};


int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

// 120. Triangle - https://leetcode.com/problems/triangle

#include "bits/stdc++.h"

using namespace std;

const int INF = (int)1e9;

class Solution {
public:
    int minimumTotal(vector<vector<int>> triangle) {
        int n = (int)triangle.size();
        vector<vector<int> > dp(n, vector<int> (n, INF));
        dp[0][0] = triangle[0][0];
        for (int row = 1; row < n; ++row) {
            for (int col = 0; col <= row; ++col) {
                if (col == row) {
                    dp[row][col] = dp[row - 1][col - 1];
                } else if (col == 0) {
                    dp[row][col] = dp[row - 1][col];
                } else {
                    dp[row][col] = min(dp[row - 1][col - 1], dp[row - 1][col]);
                }
                dp[row][col] += triangle[row][col];
            }
        }
        int result = INF;
        for (int col = 0; col < n; ++col) {
            result = min(result, dp[n - 1][col]);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

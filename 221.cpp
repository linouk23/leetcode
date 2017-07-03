// 221. Maximal Square - https://leetcode.com/problems/maximal-square

#include "bits/stdc++.h"

using namespace std;

//Suppose matrix = [[0, 1], [1, 1]], it is obvious that P[0][0] = 0,
//P[0][1] = P[1][0] = 1, what about P[1][1]? Well, to give a square
//of size larger than 1 in P[1][1], all of its three neighbors (left,
//up, left-up) should be non-zero, right? In this case, the left-up
//neighbor P[0][0] = 0, so P[1][1] can only be 1, which means that
//it contains the square of itself.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = (int)matrix.size();
        if (n == 0) { return 0; }
        int m = (int)matrix[0].size();
        
        vector<vector<int> > dp(n, vector<int> (m));
        for (int row = 0; row < n; ++row) {
            dp[row][0] = matrix[row][0] - '0';
        }
        for (int col = 0; col < m; ++col) {
            dp[0][col] = matrix[0][col] - '0';
        }
        for (int row = 1; row < n; ++row) {
            for (int col = 1; col < m; ++col) {
                if (matrix[row][col] == '0') {
                    dp[row][col] = 0;
                } else {
                    dp[row][col] = min({
                        dp[row - 1][col],
                        dp[row - 1][col - 1],
                        dp[row][col - 1],
                    }) + 1;
                }
            }
        }
        int result = 0;
        for (const auto &vec : dp) {
            for (int val : vec) {
                result = max(result, val);
            }
        }
        return result * result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

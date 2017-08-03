// 644. Maximum Average Subarray II - https://leetcode.com/problems/maximum-average-subarray-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Trick: bottom R -> top L
class Solution {
private:
    const int INF = (int)1e9;
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int rows = (int)dungeon.size();
        int cols = (int)dungeon[0].size();
        // Let dp[row][col] be the min hp needed at position (row, col).
        vector<vector<int> > dp(rows + 10, vector<int>(cols + 10, INF));
        dp[rows][cols - 1] = 1;
        dp[rows - 1][cols] = 1;
        for (int row = rows - 1; row >= 0; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                int health_needed = min(dp[row + 1][col], dp[row][col + 1]) -
                                    dungeon[row][col];
                dp[row][col] = max(1, health_needed);
            }
        }
        return dp[0][0];
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

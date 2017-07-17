// 562. Longest Line of Consecutive One in Matrix - https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Idea: 4 passes.
//   |
// ->O<- -> increase O value from L, R, D, U.
//   |
class Solution {
private:
    struct Dir {
        int diff_row, diff_col;
    };
    // Kinda where you come from to this cell:
    const int UP = 0;
    const int LEFT = 1;
    const int DIAG = 2;
    const int ANTIDIAG = 3;
    const int NUM_OF_DIRS = 4;
    vector<Dir> dirs {
        {0, -1},
        {-1, 0},
        {-1, -1},
        {-1, 1},
    };
    int find_max_value(const vector<vector<vector<int>>> &dp) {
        int result = 0;
        for (const auto &vec2d : dp) {
            for (const auto &vec1d : vec2d) {
                for (int num : vec1d) {
                    result = max(result, num);
                }
            }
        }
        return result;
    }
public:
    int longestLine(vector<vector<int>> M) {
        if (M.empty()) { return 0; }
        int n = (int)M.size();
        if (M[0].empty()) { return 0; }
        int m = (int)M[0].size();
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m,
                                       vector<int> (4, 0)));
        // (0, 0)
        if (M[0][0]) {
            dp[0][0][UP] = 1;
            dp[0][0][LEFT] = 1;
            dp[0][0][DIAG] = 1;
            dp[0][0][ANTIDIAG] = 1;
        }
        
        for (int col = 1; col < m; ++col) {
            if (M[0][col] != 1) { continue; }
            dp[0][col][UP] = 1;
            dp[0][col][LEFT] = (dp[0][col - 1][LEFT]) ? dp[0][col - 1][LEFT] + 1 : 1;
            dp[0][col][DIAG] = 1;
            dp[0][col][ANTIDIAG] = 1;
        }
        
        for (int row = 1; row < n; ++row) {
            if (M[row][0] != 1) { continue; }
            dp[row][0][UP] = (dp[row - 1][0][UP]) ? dp[row - 1][0][UP] + 1 : 1;
            dp[row][0][LEFT] = 1;
            dp[row][0][DIAG] = 1;
            dp[row][0][ANTIDIAG] = 1;
        }
        
        auto is_valid = [n, m](int row, int col) -> bool {
            return row >= 0 && col >= 0 && row < n && col < m;
        };
        
        for (int row = 1; row < n; ++row) {
            for (int col = 1; col < m; ++col) {
                if (M[row][col] != 1) { continue; }
                for (int dir = 0; dir < NUM_OF_DIRS; ++dir) {
                    dp[row][col][dir] = 1;
                    int prev_row = row + dirs[dir].diff_row;
                    int prev_col = col + dirs[dir].diff_col;
                    if (!is_valid(prev_row, prev_col)) { continue; }
                    dp[row][col][dir] += dp[prev_row][prev_col][dir];
                }
            }
        }
        return find_max_value(dp);
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(3, sol.longestLine({{0,1,1,0},{0,1,1,0},{0,0,0,1}}));
}

TEST(SolutionTest, Empty) {
    Solution sol;
    EXPECT_EQ(0, sol.longestLine({}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

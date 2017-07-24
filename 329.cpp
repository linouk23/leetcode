// 329. Longest Increasing Path in a Matrix - https://leetcode.com/problems/longest-increasing-path-in-a-matrix

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct Pos {
    int row, col;
    bool operator==(const Pos &that) const {
        return row == that.row && col == that.col;
    }
};

namespace std {
    template <>
    struct hash<Pos> {
        size_t operator () (const Pos &o) const {
            return (std::hash<int>()(o.row) << 1) ^ std::hash<int>()(o.col);
        }
    };
}

// Idea: smart memo and dfs.
class Solution {
private:
    struct Dir {
        int diff_row, diff_col;
    };
    vector<Dir> dirs = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
    };
    // pos -> len of LIS starting from pos
    unordered_map<Pos, int> cache;
    int result = 0;
    int n, m;
    // Returns len of LIS starting from start position (including).
    // [[1,2,3]  -> start = {0, 0} -> returns 3 (1,2,3)
    //  [4,1,1]]
    // which is 1 + max([2,3], [4]) = 1 + 2 = 3
    int lenOfLIPStartingFrom(const Pos &start, const vector<vector<int>> &matrix) {
        // If was already computed, then return the result
        if (cache.count(start)) { return cache[start]; }

        auto is_valid = [this, &start, &matrix](const Pos &neighbour) -> bool {
            return neighbour.row >= 0 && neighbour.row < n &&
                   neighbour.col >= 0 && neighbour.col < m &&
                   matrix[neighbour.row][neighbour.col] >
                   matrix[start.row][start.col];
        };
        
        // Len of LIS starting from start position
        // is at least one (cell itself).
        int result = 1;
        
        for (const auto &dir : dirs) {
            Pos neighbour = { start.row + dir.diff_row,
                              start.col + dir.diff_col };
            if (!is_valid(neighbour)) { continue; }
            // Update our result with 1 (cell itself) + len of
            // LIS starting from neighbour position
            // if neighbour value is valid (and bigger) so we can continue
            // our current sequence using it.
            result = max(result, 1 + lenOfLIPStartingFrom(neighbour, matrix));
        }
        
        cache[start] = result;
        return result;
    }
public:
    int longestIncreasingPath(vector<vector<int>> matrix) {
        n = (int)matrix.size();
        if (n == 0) { return 0; }
        m = (int)matrix[0].size();
        int result = INT_MIN;
        // Start from any cell.
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                result = max(result, lenOfLIPStartingFrom({row, col}, matrix));
            }
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(4, sol.longestIncreasingPath({{3,4,5},
                                            {3,2,6},
                                            {2,2,1}}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

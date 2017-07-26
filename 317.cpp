// 317. Shortest Distance from All Buildings - https://leetcode.com/problems/shortest-distance-from-all-buildings

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Instead of brute: run bfs from all buildings, store dist[row][col] ((row, col)
// - empty cell) for every bfs
// sum up dist[row][col] for all bfs (total dist from every free cell to every building)
// and then choose min (and check that we can
// visit this (i, j) cell from every building, otherwise there's no sense to build
// in (i, j) pos).

// Trick: don't use a fresh "visited" for each BFS. Instead, visited_count only
// onto the cells that were reachable from all previous buildings. From
// the first building only visited_count onto cells where grid is 0, and make them
//  -1. From the second building only visited_count onto cells where grid is -1,
// and I make them -2. And so on.

// https://discuss.leetcode.com/category/397/shortest-distance-from-all-buildings

struct Dir {
    int diff_row, diff_col;
};

class Solution {
private:
    vector<Dir> dirs = {
        {-1, 0},
        {0,  1},
        {0, -1},
        {1,  0},
    };
public:
    int shortestDistance(vector<vector<int>> grid) {
        int n = (int)grid.size(), m = (int)grid[0].size();
        int visited_count = 0, min_total_dist = INT_MAX;
        auto is_valid = [&grid, n, m](int row, int col, int count) -> bool {
            return row >= 0 && col >= 0 &&
            row < n && col < m &&
            grid[row][col] == count;
        };
        auto total = grid;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (grid[row][col] != 1) { continue; }
                min_total_dist = -1;
                auto dist = grid;
                queue<pair<int, int>> q;
                q.emplace(row, col);
                while (!q.empty()) {
                    auto from = q.front(); q.pop();
                    for (const auto &dir : dirs) {
                        int row = from.first + dir.diff_row;
                        int col = from.second + dir.diff_col;
                        if (is_valid(row, col, visited_count)) {
                            grid[row][col]--;
                            dist[row][col] = dist[from.first][from.second] + 1;
                            total[row][col] += dist[row][col] - 1;
                            q.emplace(row, col, visited_count);
                            if (min_total_dist > total[row][col])
                                min_total_dist = total[row][col];
                        }
                    }
                }
                visited_count -= 1;
            }
        }
        return min_total_dist;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

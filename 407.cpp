// 407. Trapping Rain Water II - https://leetcode.com/problems/trapping-rain-water-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct Cell {
    int row, col, val;
    bool operator==(const Cell& that) const {
        return val == that.val && row == that.row &&
               col == that.col;
    }
    bool operator>(const Cell& that) const {
        return val > that.val;
    }
};

namespace std {
    template <>
    struct hash<Cell> {
        size_t operator () (const Cell &o) const {
            return (std::hash<int>()(o.row) << 1) ^ std::hash<int>()(o.col);
        }
    };
}

class Solution {
private:
    int n, m;
    struct Dir {
        int diff_row, diff_col;
    };
    
    vector<Dir> dirs = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
    };
    unordered_set<Cell> visited;
    priority_queue<Cell, vector<Cell>, greater<Cell>> min_heap;
    void addBorders(vector<vector<int>>& heights) {
        n = (int)heights.size();
        m = (int)heights.front().size();
        for (int row = 1; row < n - 1; ++row) {
            Cell cell = {row, 0, heights[row][0]};
            min_heap.push(cell); visited.insert(cell);
            cell = {row, m - 1, heights[row][m - 1]};
            min_heap.push(cell); visited.insert(cell);
        }
        for (int col = 1; col < m - 1; ++col) {
            Cell cell = {0, col, heights[0][col]};
            min_heap.push(cell); visited.insert(cell);
            cell = {n - 1, col, heights[n - 1][col]};
            min_heap.push(cell); visited.insert(cell);
        }
        Cell cell = {0, 0, heights[0][0]};
        min_heap.push(cell); visited.insert(cell);
        cell = {0, m - 1, heights[0][m - 1]};
        min_heap.push(cell); visited.insert(cell);
        cell = {n - 1, 0, heights[n - 1][0]};
        min_heap.push(cell); visited.insert(cell);
        cell = {n - 1, m - 1, heights[n - 1][m - 1]};
        min_heap.push(cell); visited.insert(cell);
    }
    void add_neighbours(const Cell &cell, vector<vector<int>>& heights, int &result, int max_so_far) {
        auto is_valid = [this](const Cell &cell) -> bool {
            return cell.row >= 0 && cell.col >= 0 &&
            cell.row < n && cell.col < m;
        };
        
        for (const auto &dir : dirs) {
            Cell neighbour = { cell.row + dir.diff_row,
                               cell.col + dir.diff_col
            };
            
            if (!is_valid(neighbour)) { continue; }
            neighbour.val = heights[neighbour.row][neighbour.col];
            if (visited.count(neighbour)) { continue; }
            
            min_heap.push(neighbour);
            visited.insert(neighbour);
            
            if (max_so_far > neighbour.val) {
                result += (max_so_far - neighbour.val);
            }
        }
    }
public:
    int trapRainWater(vector<vector<int>> heights) {
        if (heights.empty()) { return 0; }
        int max_so_far = INT_MIN;
        addBorders(heights);
        int result = 0;
        while (!min_heap.empty()) {
            auto cell = min_heap.top(); min_heap.pop();
            max_so_far = max(max_so_far, cell.val);
            add_neighbours(cell, heights, result, max_so_far);
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    vector<vector<int>> input = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1},
    };
    EXPECT_EQ(4, sol.trapRainWater(input));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

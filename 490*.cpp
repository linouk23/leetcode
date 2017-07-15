// 490. The Maze - https://leetcode.com/problems/the-maze

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

enum Type {WALL, EMPTY};

struct Cell {
    int row, col;
    bool operator==(const Cell &that) const {
        return that.row == row && that.col == col;
    }
};
namespace std {
    template <>
    struct hash<Cell> {
        size_t operator () (const Cell &p) const {
            return (std::hash<int>()(p.row) << 1) ^ std::hash<int>()(p.col);
        }
    };
}

struct Dir {
    int diff_row, diff_col;
};

class Solution {
private:
    FRIEND_TEST(SolutionTest, IsInField);
    int n, m;
    unordered_set<Cell> visited_stop;
    vector<Dir> dirs = {
        {-1, 0},
        {1,  0},
        {0, -1},
        {0,  1},
    };
    bool is_in_field(const Cell& cell) {
        return cell.row >= 0 && cell.col >= 0 &&
               cell.row < n  && cell.col < m;
    }
public:
    bool hasPath(vector<vector<int>> &maze, vector<int> s, vector<int> d) {
        Cell start = {s.front(), s.back()};
        Cell finish = {d.front(), d.back()};
        n = (int)maze.size();
        m = (n == 0) ? 0 : (int)maze[0].size();
        
        if (m == 0) { return false; }
        
        auto get_type = [maze](const Cell &cell) -> bool {
            return maze[cell.row][cell.col] == 0 ? Type::EMPTY : Type::WALL;
        };
        
        visited_stop.insert(start);
        queue<Cell> q;
        q.push(start);
        while(!q.empty()) {
            auto cell = q.front(); q.pop();
            for (const auto &dir : dirs) {
                Cell prev, next;
                prev = next = cell;
                
                while (is_in_field(next) && get_type(next) == Type::EMPTY) {
                    prev = next;
                    next = {next.row + dir.diff_row, next.col + dir.diff_col};
                };
                
                if (visited_stop.count(prev)) { continue; }
                visited_stop.insert(prev);
                q.push(prev);
            }
        }
        return visited_stop.count(finish);
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    vector<vector<int>> matrix = {
        {0, 0, 1, 0, 0},  {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},  {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };
    EXPECT_EQ(true, sol.hasPath(matrix,  {0, 4}, {4, 4}));
    EXPECT_EQ(false, sol.hasPath(matrix, {0, 4}, {3, 2}));
}

TEST(SolutionTest, IsInField) {
    Solution sol;
    vector<vector<int>> matrix = {
        {0, 0, 1, 0, 0},  {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},  {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };
    sol.hasPath(matrix, {0, 0}, {0, 0});
    EXPECT_EQ(true, sol.is_in_field({1, 1}));
    EXPECT_EQ(false, sol.is_in_field({-1, 1}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

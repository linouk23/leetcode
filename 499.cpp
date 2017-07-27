// 499. The Maze III - https://leetcode.com/problems/the-maze-iii

// Trick: Similar to Maze II, add an opportunity to restore path.

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

// Idea: continue while can improve shortest path
class Solution {
private:
    FRIEND_TEST(SolutionTest, IsInField);
    int n, m;
    vector<Dir> dirs = {
        {1,  0}, // d
        {0, -1}, // l
        {0,  1}, // r
        {-1, 0}, // u
    };
    map<Dir, char> path = {
        {{1,  0}, 'd'}, // d
        {{0, -1}, 'l'}, // l
        {{0,  1}, 'r'}, // r
        {{-1, 0}, 'u'}, // u
    };
    bool is_in_field(const Cell& cell) {
        return cell.row >= 0 && cell.col >= 0 &&
        cell.row < n  && cell.col < m;
    }
    int manh_dist(const Cell& c1, const Cell& c2) {
        return abs(c1.row - c2.row) + abs(c1.col - c2.col);
    }
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int> s, vector<int> d) {
        Cell start = {s.front(), s.back()};
        Cell finish = {d.front(), d.back()};
        n = (int)maze.size();
        m = (n == 0) ? 0 : (int)maze[0].size();
        
        if (m == 0) { return false; }
        
        auto get_type = [maze](const Cell &cell) -> bool {
            return maze[cell.row][cell.col] == 0 ? Type::EMPTY : Type::WALL;
        };
        
        dist[start] = 0;
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
                
                // Push into the Q iff we've improved shortest path to prev,
                // so we'll be able to improve neighbours of prev (think about
                // dijkstra).
                if (dist.count(prev)) {
                    if (dist[prev] > dist[cell] + manh_dist(cell, prev)) {
                        dist[prev] = dist[cell] + manh_dist(cell, prev);
                        q.push(prev);
                    }
                } else {
                    dist[prev] = dist[cell] + manh_dist(cell, prev);
                    q.push(prev);
                }
            }
        }
        if (!dist.count(finish)) {
            return -1;
        };
        return dist[finish];
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    vector<vector<int>> matrix = {
        {0, 0, 0, 0, 0},  {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0},  {0, 1, 0, 0, 1},
        {0, 1, 0, 0, 0}
    };
    EXPECT_EQ("lul", sol.findShortestWay(matrix, {4, 3}, {0, 1}));
    matrix = {
        {0, 0, 0, 0, 0},  {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0},  {0, 1, 0, 0, 1},
        {0, 1, 0, 0, 0}
    };
    EXPECT_EQ("impossible", sol.findShortestWay(matrix, {4, 3}, {3, 0}));
}

TEST(SolutionTest, IsInField) {
    Solution sol;
    vector<vector<int>> matrix = {
        {0, 0, 0, 0, 0},  {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0},  {0, 1, 0, 0, 1},
        {0, 1, 0, 0, 0}
    };
    sol.findShortestWay(matrix, {4, 3}, {0, 1});
    EXPECT_EQ(true, sol.is_in_field({1, 1}));
    EXPECT_EQ(false, sol.is_in_field({-1, 1}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

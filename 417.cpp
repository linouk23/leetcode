// 417. Pacific Atlantic Water Flow - https://leetcode.com/problems/pacific-atlantic-water-flow

#include "bits/stdc++.h"

using namespace std;

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
    queue<Cell> atlanticQ, pacificQ;
    unordered_set<Cell> visitedAtlantic, visitedPacific;
    vector<Dir> dirs = {
        {-1, 0},
        {1,  0},
        {0, -1},
        {0,  1},
    };
    int n, m;
    vector<vector<int> > matrix_;
    
    void initPacific() {
        for (int row = 0; row < n; ++row) {
            pacificQ.push({row, 0});
            visitedPacific.insert({row, 0});
        }
        for (int col = 1; col < m; ++col) {
            pacificQ.push({0, col});
            visitedPacific.insert({0, col});
        }
    }
    void initAtlantic() {
        for (int row = 0; row < n; ++row) {
            atlanticQ.push({row, m - 1});
            visitedAtlantic.insert({row, m - 1});
        }
        for (int col = 0; col < m - 1; ++col) {
            atlanticQ.push({n - 1, col});
            visitedAtlantic.insert({n - 1, col});
        }
    }
    void initQueues() {
        initPacific();
        initAtlantic();
    }
    void bfsPacific() {
        auto isValidCell = [this](const Cell& cell) -> bool {
            return cell.row >= 0 && cell.col >= 0 &&
                   cell.row < n && cell.col < m;
        };
        auto isNeighbourHigher = [this](const Cell& cell, const Cell& n) -> bool {
            return matrix_[cell.row][cell.col] <= matrix_[n.row][n.col];
        };
        while (!pacificQ.empty()) {
            auto cell = pacificQ.front(); pacificQ.pop();
            for (const auto &dir : dirs) {
                Cell neighbour = {cell.row + dir.diff_row, cell.col + dir.diff_col};
                if (!isValidCell(neighbour)) { continue; }
                if (!isNeighbourHigher(cell, neighbour)) { continue; }
                if (visitedPacific.count(neighbour)) { continue; }
                pacificQ.push(neighbour);
                visitedPacific.insert(neighbour);
            }
        }
    }
    void bfsAtlantic() {
        auto isValidCell = [this](const Cell& cell) -> bool {
            return cell.row >= 0 && cell.col >= 0 &&
            cell.row < n && cell.col < m;
        };
        auto isNeighbourHigher = [this](const Cell& cell, const Cell& n) -> bool {
            return matrix_[cell.row][cell.col] <= matrix_[n.row][n.col];
        };
        while(!atlanticQ.empty()) {
            auto cell = atlanticQ.front(); atlanticQ.pop();
            for (const auto &dir : dirs) {
                Cell neighbour = {cell.row + dir.diff_row,
                    cell.col + dir.diff_col};
                if (!isValidCell(neighbour)) { continue; }
                if (!isNeighbourHigher(cell, neighbour)) { continue; }
                if (visitedAtlantic.count(neighbour)) { continue; }
                atlanticQ.push(neighbour);
                visitedAtlantic.insert(neighbour);
            }
        }
    }
    void runBFS() {
        bfsPacific();
        bfsAtlantic();
    }
    vector<pair<int, int>> findIntersection() {
        vector<pair<int, int> > result;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (visitedPacific.count({row, col}) &&
                    visitedAtlantic.count({row, col})) {
                    result.push_back({row, col});
                }
            }
        }
        return result;
    }
    bool initFields(const vector<vector<int>>& matrix) {
        matrix_ = matrix;
        n = (int)matrix_.size();
        if (n == 0) { return false; }
        m = (int)matrix_[0].size();
        return true;
    }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
        if (!initFields(matrix)) { return {}; }
        initQueues();
        runBFS();
        return findIntersection();
    }
};


int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 130. Surrounded Regions - https://leetcode.com/problems/surrounded-regions

#include "bits/stdc++.h"

using namespace std;

struct Cell {
    int row, col;
    bool operator==(const Cell& that) const {
        return row == that.row && col == that.col;
    }
};

struct Dir {
    int diff_row, diff_col;
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
    queue<Cell> q;
    unordered_set<Cell> visited;
    vector<Dir> dirs = {
        {-1, 0},
        {0,  1},
        {0, -1},
        {1,  0},
    };
    void initFields(vector<vector<char>>& board) {
        n = (int)board.size();
        m = (n > 0) ? (int)board[0].size() : 0;
    }
    void initQ(vector<vector<char>> board) {
        auto isFree = [this, &board](int row, int col) -> bool {
            return board[row][col] == 'O';
        };
        for (int row = 0; row < n; ++row) {
            if (isFree(row, 0)) {
                visited.insert({row, 0});
                q.push({row, 0});
            }
            if (isFree(row, m - 1)) {
                visited.insert({row, m - 1});
                q.push({row, m - 1});
            }
        }
        for (int col = 1; col < m - 1; ++col) {
            if (isFree(0, col)) {
                visited.insert({0, col});
                q.push({0, col});
            }
            if (isFree(n - 1, col)) {
                visited.insert({n - 1, col});
                q.push({n - 1, col});
            }
        }
    }
    void runBFS(vector<vector<char>>& board) {
        auto isValid = [this, &board](const Cell &o) -> bool {
            return o.row >= 0 && o.row < n &&
            o.col >= 0 && o.col < m;
        };
        auto isFree = [this, &board](const Cell &o) -> bool {
            return board[o.row][o.col] == 'O';
        };
        while(!q.empty()) {
            auto cell = q.front(); q.pop();
            for (const auto &dir : dirs) {
                Cell neighbour = {cell.row + dir.diff_row,
                    cell.col + dir.diff_col};
                if (!isValid(neighbour)) { continue; }
                if (!isFree(neighbour)) { continue; }
                if (visited.count(neighbour)) { continue; }
                visited.insert(neighbour);
                q.push(neighbour);
            }
        }
    }
    void fill(vector<vector<char>>& board) {
        auto isFree = [this, &board](int row, int col) -> bool {
            return board[row][col] == 'O';
        };
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (isFree(row, col) && !visited.count({row, col})) {
                    board[row][col] = 'X';
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        initFields(board);
        initQ(board);
        runBFS(board);
        fill(board);
    }
};


int main() {
    ios::sync_with_stdio(false);
    return 0;
}

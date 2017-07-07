// 529. Minesweeper - https://leetcode.com/problems/minesweeper

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
    int n, m;
    unordered_set<Cell> visited;
//    vector<Dir> dirs = {
//        {-1, 0},
//        {1,  0},
//        {0, -1},
//        {0,  1},
//    };
    
    int find_mines(Cell cell, vector<vector<char>>& board) {
        int result = 0;
        for (int diff_row = -1; diff_row <= 1; ++diff_row) {
            for (int diff_col = -1; diff_col <= 1; ++diff_col) {
                if (diff_row == 0 && diff_col == 0) { continue; }
                Cell neighbour = { cell.row + diff_row,
                                   cell.col + diff_col };
                if (!isValidCell(neighbour)) { continue; }
                if (board[neighbour.row][neighbour.col] == 'M' ||
                    board[neighbour.row][neighbour.col] == 'X') {
                    result += 1;
                }
            }
        }
        return result;
    }
    
    bool isValidCell(const Cell& cell) {
        return cell.row >= 0 && cell.col >= 0 &&
               cell.row < n && cell.col < m;
    }
    
    bool process_click_and_stop(Cell cell, vector<vector<char>>& board) {
        if (board[cell.row][cell.col] == 'M') {
            board[cell.row][cell.col] = 'X';
            return true;
        } else {
            int num_of_mines = find_mines(cell, board);
            if (num_of_mines) {
                board[cell.row][cell.col] = '0' + num_of_mines;
                return true;
            } else {
                board[cell.row][cell.col] = 'B';
            }
        }
        return false;
    }
    
    void dfs(Cell cell, vector<vector<char>>& board) {
        visited.insert(cell);
        
        // Stop if mine was found.
        if (process_click_and_stop(cell, board)) { return; };
        
        for (int diff_row = -1; diff_row <= 1; ++diff_row) {
            for (int diff_col = -1; diff_col <= 1; ++diff_col) {
                if (diff_row == 0 && diff_col == 0) { continue; }
                Cell neighbour = { cell.row + diff_row,
                                   cell.col + diff_col };
                if (isValidCell(neighbour) && !visited.count(neighbour)) {
                    dfs(neighbour, board);
                }
            }
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        n = (int)board.size();
        m = (n > 0) ? (int)board[0].size() : 0;
        Cell start = { click[0], click[1] };
        dfs(start, board);
        return board;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

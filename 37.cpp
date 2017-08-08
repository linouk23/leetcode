// 37. Sudoku Solver - https://leetcode.com/problems/sudoku-solver

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    vector<vector<char>> result;
    int n;
    char dot = '.';
    bool check(vector<vector<char>> &board, int row, int col, int val,
               vector<deque<bool>> &rows, vector<deque<bool>> &cols,
               vector<deque<bool>> &cubes) {
        int cube_idx = 3 * (row / 3) + col / 3;
        return rows[row][val - 1] || cols[col][val - 1] ||
        cubes[cube_idx][val - 1];
    }
    void set_val(vector<vector<char>> &board, int row, int col, int val,
                 vector<deque<bool>> &rows, vector<deque<bool>> &cols,
                vector<deque<bool>> &cubes, bool value_to_set) {
        int cube_idx = 3 * (row / 3) + col / 3;
        rows[row][val - 1] = cols[col][val - 1] = value_to_set;
        cubes[cube_idx][val - 1] = value_to_set;
    }
    void call_helper(vector<vector<char>> board, int row, int col,
                     vector<deque<bool>> rows,
                     vector<deque<bool>> cols,
                     vector<deque<bool>> cubes){
        if (col != n - 1) {
            helper(board, row, col + 1, rows, cols, cubes);
        } else {
            helper(board, row + 1, 0, rows, cols, cubes);
        }
    }
    void helper(vector<vector<char>> board, int row, int col,
                vector<deque<bool>> rows,
                vector<deque<bool>> cols,
                vector<deque<bool>> cubes) {
        if (row == n) {
            result = board;
            return;
        }
        if (!result.empty()) { return; }
        
        if (board[row][col] != dot) {
            call_helper(board, row, col, rows,
                        cols, cubes);
        }
        for (int val = 1; val <= 9; ++val) {
            if (check(board, row, col, val,
                      rows, cols, cubes)) {
                continue;
            }
            // Trick.
            board[row][col] = '0' + val;
            set_val(board, row, col, val,
                    rows, cols, cubes, true);
            call_helper(board, row, col, rows,
                        cols, cubes);
            set_val(board, row, col, val,
                    rows, cols, cubes, false);
        }
    }
public:
    void solveSudoku(vector<vector<char>> &board) {
        // n = (int)board.size();
        // m = (n > 0) ? (int)board[0].size() : 0;
        n = 9;
        vector<deque<bool> > rows(n, deque<bool> (n, false));
        auto cols = rows;
        vector<deque<bool> > cubes(n, deque<bool> (n, false));
        
        // Use current configuration.
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (board[row][col] == dot) { continue; }
                int val = board[row][col] - '0';
                set_val(board, row, col, val,
                        rows, cols, cubes, true);
            }
        }
        
        helper(board, 0, 0, rows, cols, cubes);
        board = result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

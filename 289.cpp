// 289. Game of Life - https://leetcode.com/problems/game-of-life

#include "bits/stdc++.h"

using namespace std;

//[2nd bit, 1st bit] = [next state, current state]
//
//- 00  dead (next) <- dead (current)
//- 01  dead (next) <- live (current)
//- 10  live (next) <- dead (current)
//- 11  live (next) <- live (current)

class Solution {
private:
    vector<vector<int>> board_;
    bool is_ok_cell(int row, int col) {
        return row >= 0 && col >= 0 &&
               row < int(board_.size()) && col < int(board_[0].size());
    }
    
    int get_neighbours(int row, int col) {
        int num_of_neighbours = 0;
        for (int drow = -1; drow <= 1; ++drow) {
            for (int dcol = -1; dcol <= 1; ++dcol) {
                if (drow == dcol && drow == 0) { continue; }
                if (!is_ok_cell(row + drow, col + dcol)) { continue; }
                if (board_[row + drow][col + dcol] % 2) {
                    ++num_of_neighbours;
                }
            }
        }
        return num_of_neighbours;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        board_ = board;
        int n = (int)board.size();
        if (n == 0) { return; }
        int m = (int)board[0].size();
        
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                int num_of_neighbours = get_neighbours(row, col);
                if (board[row][col] % 2) {
                    if (num_of_neighbours < 2 || num_of_neighbours > 3) {
                        board[row][col] = board[row][col] & (~(1 << 1));
                    } else {
                        board[row][col] = board[row][col] | ((1 << 1));
                    }
                } else {
                    if (num_of_neighbours == 3) {
                        board[row][col] = board[row][col] | ((1 << 1));
                    } else {
                        board[row][col] = board[row][col] & (~(1 << 1));
                    }
                }
            }
        }
        
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                board[row][col] >>= 1;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

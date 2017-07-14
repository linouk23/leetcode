// 348. Design Tic-Tac-Toe - https://leetcode.com/problems/design-tic-tac-toe

#include "bits/stdc++.h"

using namespace std;

// Idea: we don't need to keep track of an entire n^2 board.
// We only need to keep a count for each row and column.
// If at any time a row or column matches the size of the
// board then that player has won.

// To keep track of which player, add one for Player1 and -1 for Player2.
class TicTacToe {
private:
    int n;
    vector<int> rows, cols;
    int diag, anti_diag;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        rows.resize(n, 0);
        cols.resize(n, 0);
        diag = anti_diag = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
     @param row The row of the board.
     @param col The column of the board.
     @param player The player, can be either 1 or 2.
     @return The current winning condition, can be either:
     0: No one wins.
     1: Player 1 wins.
     2: Player 2 wins. */
    int move(int row, int col, int player) {
        int term = player == 1 ? 1 : -1;
        
        rows[row] += term;
        cols[col] += term;
        if (row == col) { diag += term; }
        
        if (col == (n - row - 1)) { anti_diag += term; }
        
        if (abs(rows[row]) == n||
            abs(cols[col]) == n ||
            abs(diag) == n  ||
            abs(anti_diag) == n) {
            return player;
        }
        
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

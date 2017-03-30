// 419. Battleships in a Board - https://leetcode.com/problems/battleships-in-a-board

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int num_of_rows = (int)board.size();
        if (num_of_rows == 0) { return 0; }
        int num_of_cols = (int)board[0].size();

        int count = 0;
        for (int row = 0; row < num_of_rows; ++row) {
            for (int column = 0; column < num_of_cols; ++column) {
                if (board[row][column] == '.') { continue; }
                if (row >= 1 && board[row - 1][column] == 'X') { continue; }
                if (column >= 1 && board[row][column - 1] == 'X') { continue; }
                ++count;
            }
        }

        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    return 0;
}

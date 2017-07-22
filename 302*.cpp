// 302. Smallest Rectangle Enclosing Black Pixels - https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

/*
 Suppose we have a 2D array
 "000000111000000"
 "000000101000000"
 "000000101100000"
 "000001100100000"
Imagine we project the 2D array to the bottom axis with
the rule "if a column has any black pixel it's projection
is black otherwise white". The projected 1D array is
 "000001111100000"
*/

class Solution {
private:
    int binSearchMin(vector<vector<char>> &board, int L, int R, bool isRow) {
        // find 1st 1 from 000001111 -> R
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (isRow ? hasOneInRow(board, M) : hasOneInCol(board, M)) {
                R = M;
            } else {
                L = M;
            }
        }
        return R;
    }
    int binSearchMax(vector<vector<char>> &board, int L, int R, bool isRow) {
        // find last 1 from 1111000 -> L
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (isRow ? hasOneInRow(board, M) : hasOneInCol(board, M)) {
                L = M;
            } else {
                R = M;
            }
        }
        return L;
    }
    bool hasOneInRow(vector<vector<char>> &board, int M) {
        int m = (int)board[0].size();
        for (int col = 0; col < m; ++col) {
            if (board[M][col] == '1') {
                return true;
            }
        }
        return false;
    }
    bool hasOneInCol(vector<vector<char>> &board, int M) {
        int n = (int)board.size();
        for (int row = 0; row < n; ++row) {
            if (board[row][M] == '1') {
                return true;
            }
        }
        return false;
    }
public:
    int minArea(vector<vector<char>> &board, int startRow, int startCol) {
        int minRow = binSearchMin(board, -1, startRow, true);
        int maxRow = binSearchMax(board, startRow, (int)board.size(), true);
        int minCol = binSearchMin(board, -1, startCol, false);
        int maxCol = binSearchMax(board, startCol, (int)board[0].size(), false);
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

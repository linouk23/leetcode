// 73. Set Matrix Zeroes - https://leetcode.com/problems/set-matrix-zeroes

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool fst_row_has_zero = false, fst_column_has_zero = false;
        int rows = (int)matrix.size();
        if (rows == 0) { return; }
        int cols = (int)matrix[0].size();
    
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < cols; ++column) {
                if (!matrix[row][column]) {
                    if (row == 0)    { fst_row_has_zero = true; }
                    if (column == 0) { fst_column_has_zero = true; }
                    matrix[0][column] = 0;
                    matrix[row][0] = 0;
                }
            }
        }
        for (int row = 1; row < rows; ++row) {
            for (int column = 1; column < cols; ++column) {
                if (!matrix[row][0] || !matrix[0][column]) {
                    matrix[row][column] = 0;
                }
            }
        }
        
        if (fst_row_has_zero) {
            for (int column = 0; column < cols; ++column) {
                matrix[0][column] = 0;
            }
        }
        
        if (fst_column_has_zero) {
            for (int row = 0; row < rows; ++row) {
                matrix[row][0] = 0;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

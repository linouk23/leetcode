// 59. Spiral Matrix II - https://leetcode.com/problems/spiral-matrix-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int> (n));
        
        int row_start = 0;
        int row_finish = n - 1;
        int col_start = 0;
        int col_finish = n - 1;
        
        int value = 1;
        
        while (row_start <= row_finish && col_start <= col_finish) {
            for (int col = col_start; col <= col_finish; ++col) {
                result[row_start][col] = value++;
            }
            ++row_start;
            
            for (int row = row_start; row <= row_finish; ++row) {
                result[row][col_finish] = value++;
            }
            --col_finish;
            
            for (int col = col_finish; col >= col_start; col--) {
                if (row_start <= row_finish)
                    result[row_finish][col] = value++;
            }
            --row_finish;
            
            for (int row = row_finish; row >= row_start; --row) {
                if (col_start <= col_finish)
                    result[row][col_start] = value++;
            }
            ++col_start;
        }
        
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

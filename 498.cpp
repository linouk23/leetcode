// 498. Diagonal Traverse - https://leetcode.com/problems/diagonal-traverse

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        if (n == 0) { return {}; }
        int m = (int)matrix[0].size();
        
        vector<int> result(n * m);
        
        struct Direction {
            int diff_row, diff_col;
        };
        vector<Direction> dirs = {
            {-1,  1}, // Up && Right
            { 1, -1}, // Down && Left
        };
        
        int row, col, cur_dir_idx;
        row = col = cur_dir_idx = 0;
        
        for (int idx = 0; idx < n * m; ++idx) {
            result[idx] = matrix[row][col];
            row += dirs[cur_dir_idx].diff_row;
            col += dirs[cur_dir_idx].diff_col;
            if (row >= n) { row = n - 1; col += 2; cur_dir_idx = 1 - cur_dir_idx;}
            if (col >= m) { col = m - 1; row += 2; cur_dir_idx = 1 - cur_dir_idx;}
            if (row < 0)  { row = 0; cur_dir_idx = 1 - cur_dir_idx;}
            if (col < 0)  { col = 0; cur_dir_idx = 1 - cur_dir_idx;}
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

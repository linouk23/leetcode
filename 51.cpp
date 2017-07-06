// 51. N-Queens - https://leetcode.com/problems/n-queens

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n_rows;
    int n_diags;
    char queen = 'Q';
    char dot = '.';
    vector<vector<string>> result;
    
    void helper(int cur_row, vector<bool> rows, vector<bool> cols, vector<bool> ldiags, vector<bool> rdiags, vector<string> field) {
        if (cur_row == n_rows) {
            result.emplace_back(field);
            return;
        }
        
        for (int col = 0; col < n_rows; ++col) {
            int lind = cur_row + col;
            int rind = n_rows - 1 - cur_row + col;
            if (rows[cur_row] || cols[col] || ldiags[lind] || rdiags[rind]) {
                continue;
            }
            field[cur_row][col] = queen;
            rows[cur_row] = cols[col] = ldiags[lind] = rdiags[rind] = true;
            helper(cur_row + 1, rows, cols, ldiags, rdiags, field);
            rows[cur_row] = cols[col] = ldiags[lind] = rdiags[rind] = false;
            field[cur_row][col] = dot;
        }
    }
public:
    vector<vector<string>> solveNQueens(int num_of_rows) {
        n_rows = num_of_rows;
        vector<bool> rows(n_rows, false);
        auto cols = rows;
        vector<bool> ldiags(2 * n_rows, false);
        auto rdiags = ldiags;
        vector<string> field(n_rows, string(n_rows, dot));
        helper(0, rows, cols, ldiags, rdiags, field);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

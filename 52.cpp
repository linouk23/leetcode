// 52. N-Queens II - https://leetcode.com/problems/n-queens-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n, result = 0;
    void helper(int cur_row, deque<bool> rows, deque<bool> cols, deque<bool> dL, deque<bool> dR) {
        if (cur_row == n) {
            ++result;
            return;
        }
        for (int col = 0; col < n; ++col) {
            int indL = cur_row + col;
            // Using the 1st col:
            int indR = n - 1 - cur_row + col;
            if (rows[cur_row] || cols[col] || dL[indL] || dR[indR]) {
                continue;
            }
            rows[cur_row] = cols[col] = dL[indL] = dR[indR] = true;
            helper(cur_row + 1, rows, cols, dL, dR);
            rows[cur_row] = cols[col] = dL[indL] = dR[indR] = false;
        }
    }
public:
    int totalNQueens(int n) {
        this->n = n;
        deque<bool> rows(n, false);
        auto cols = rows;
        deque<bool> dL(2 * n, false);
        auto dR = dL;
        helper(0, rows, cols, dL, dR);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    Solution sol;
    sol.solveNQueens(4);
//    sol.solve({{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}});
    return 0;
}

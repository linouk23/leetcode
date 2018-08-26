// 52. N-Queens II - https://leetcode.com/problems/n-queens-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n, result = 0;
    void generate(int row, vector<bool> &cols, vector<bool> &ldiag, vector<bool> &rdiag) {
        if (row == n) {
            ++result;
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            bool isCellUnderAttack = cols[col] || ldiag[row + col] || rdiag[n - row + col - 1];
            if (isCellUnderAttack) { continue; }
            
            cols[col] = ldiag[row + col] = rdiag[n - row + col - 1] = true;
            
            generate(row + 1, cols, ldiag, rdiag);
            
            cols[col] = ldiag[row + col] = rdiag[n - row + col - 1] = false;
        }
    }
public:
    int totalNQueens(int n) {
        this->n = n;
        vector<bool> cols(n, false);
        vector<bool> ldiag(2 * n, false);
        auto rdiag = ldiag;
        generate(0, cols, ldiag, rdiag);
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

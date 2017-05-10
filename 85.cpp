// 85. Maximal Rectangle - https://leetcode.com/problems/maximal-rectangle

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> matrix) {
        int n = (int)matrix.size();
        if (n == 0) { return 0; }
        int m = (int)matrix[0].size();
        vector<vector<int> > dp(n, vector<int> (m, 0));
        vector<vector<int> > conseq_left(n, vector<int> (m, 0));
        
        for (int row = 0; row < n; ++row) {
            if (matrix[row][0] == '0') {
                conseq_left[row][0] = 0;
            } else {
                conseq_left[row][0] = 1;
            }
        }
        
        for (int row = 0; row < n; ++row) {
            for (int column = 1; column < m; ++column) {
                if (matrix[row][column] == '0') { continue; }
                conseq_left[row][column] = conseq_left[row][column - 1] + 1;
            }
        }
        
        int result = 0;
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < m; ++column) {
                int min_width = INT_MAX;
                for (int height = 1; height + row - 1< n; ++height) {
                    if (conseq_left[row][column] == 0) { break; }
                    min_width = min(min_width, conseq_left[row + height - 1][column]);
                    result = max(result,
                                 height * min_width);
                }
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

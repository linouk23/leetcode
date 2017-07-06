// 304. Range Sum Query 2D - Immutable - https://leetcode.com/problems/range-sum-query-2d-immutable

#include "bits/stdc++.h"

using namespace std;

class NumMatrix {
private:
    vector<vector<int> > prefix;
    int n, m;
public:
    NumMatrix(vector<vector<int>> matrix) {
        n = (int)matrix.size();
        m = n > 0 ? (int)matrix[0].size() : 0;
        
        prefix.resize(n + 1, vector<int> (m + 1, 0));
        for (int row = 1; row <= n; ++row) {
            for (int col = 1; col <= m; ++col) {
                int value = matrix[row - 1][col - 1];

                prefix[row][col] =
                    prefix[row - 1][col] + prefix[row][col - 1] -
                    prefix[row - 1][col - 1] + value;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        ++row1; ++row2; ++col1; ++col2;
        return prefix[row2][col2] - prefix[row2][col1 - 1] -
               prefix[row1 - 1][col2] + prefix[row1 - 1][col1 - 1];
    }
};


int main() {
    ios::sync_with_stdio(false);
    return 0;
}

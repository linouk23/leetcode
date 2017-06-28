// 62. Unique Paths - https://leetcode.com/problems/unique-paths

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > result(m, vector<int> (n, 0));
        result[0][0] = 1;
        for (int row = 1; row < m; ++row) {
            result[row][0] = 1;
        }
        for (int col = 1; col < n; ++col) {
            result[0][col] = 1;
        }
        for (int row = 1; row < m; ++row) {
            for (int col = 1; col < n; ++col) {
                result[row][col] += result[row - 1][col] + result[row][col - 1];
            }
        }
        return result[m - 1][n - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

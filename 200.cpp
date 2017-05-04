// 200. Number of Islands - https://leetcode.com/problems/number-of-islands

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void destroy(int row, int column) {
        grid_[row][column] = '0';
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, 1, -1, 0};
        auto is_valid_cell = [this](int row, int column) -> bool {
            return row >= 0 && row < n && column >= 0 && column < m &&
                   grid_[row][column] == '1';
        };
        for (int step = 0; step < 4; ++step) {
            int new_row = row + dx[step];
            int new_column = column + dy[step];
            if (is_valid_cell(new_row, new_column)) {
                destroy(new_row, new_column);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        grid_ = grid;
        n = (int)grid.size();
        if (n == 0) { return 0; }
        m = (int)grid[0].size();
        int result = 0;
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < m; ++column) {
                if (grid_[row][column] == '1') {
                    ++result;
                    destroy(row, column);
                }
            }
        }
        return result;
    }
private:
    vector<vector<char> > grid_;
    int n, m;
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

// 463. Island Perimeter - https://leetcode.com/problems/island-perimeter

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<int>> matrix;

public:
    bool is_valid_pair(const pair<int, int> &op) {
        return (op.first >= 0  && op.first < n &&
            op.second >= 0 && op.second < m);
    }

    bool is_one(const pair<int, int> &op) {
        int row = op.first;
        int column = op.second;

        if (is_valid_pair({row, column})) {
            return matrix[row][column] == 1;
        }

        return false;
    }

    bool is_zero(const pair<int, int> &op) {
        return !is_one(op);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        matrix = grid;
        n = matrix.size();
        if (n == 0) {
            return 0;
        }

        m = matrix[0].size();
        
        int answer = 0;
        for (int row = -1; row <= n; ++row) {
            for (int column = -1; column <= m; ++column) {
                if (!is_valid_pair({row, column}) || is_zero({row, column})) {
                    if (is_one({row + 1, column})) {
                        ++answer;
                    }

                    if (is_one({row - 1, column})) {
                        ++answer;
                    }

                    if (is_one({row, column + 1})) {
                        ++answer;
                    }

                    if (is_one({row, column - 1})) {
                        ++answer;
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<vector<int>> input = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    assert(solution.islandPerimeter(input) == 16);

    input = {};
    assert(solution.islandPerimeter(input) == 0);

    input = {{}};
    assert(solution.islandPerimeter(input) == 0);

    return 0;
}

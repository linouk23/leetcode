// 361. Bomb Enemy - https://leetcode.com/problems/bomb-enemy

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Idea: 4 passes.
//   |
// ->O<- -> increase O value from L, R, D, U.
//   |
class Solution {
private:
    int find_max_value(const vector<vector<int>> &dp) {
        int result = 0;
        for (const auto &nums : dp) {
            for (int num : nums) {
                result = max(result, num);
            }
        }
        return result;
    }
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() == 0 || grid[0].empty()) { return 0; }
        int NUM_OF_ROWS = (int)grid.size();
        int NUM_OF_COLS = (int)grid[0].size();
        int result = 0;
        vector<vector<int>> dp(NUM_OF_ROWS, vector<int> (NUM_OF_COLS, 0));
        // for each row: ->, <-
        for (int row = 0; row < NUM_OF_ROWS; ++row){
            int count_so_far = 0;
            for (int col = 0; col < NUM_OF_COLS; ++col){
                if (grid[row][col] == '0'){
                    dp[row][col] += count_so_far;
                } else if (grid[row][col] == 'E'){
                    ++count_so_far;
                } else { // reset the count_so_farer
                    count_so_far = 0;
                }
            }
            count_so_far = 0;
            for (int col = NUM_OF_COLS - 1; col >= 0; --col){
                if (grid[row][col] == '0'){
                    dp[row][col] += count_so_far;
                } else if (grid[row][col] == 'E'){
                    ++count_so_far;
                } else {
                    count_so_far = 0;
                }
            }
        }
        // for each col: D/U
        for (int col = 0; col < NUM_OF_COLS; ++col){
            int count_so_far = 0;
            for (int row = 0; row < NUM_OF_ROWS; ++row){
                if (grid[row][col] == '0'){
                    dp[row][col] += count_so_far;
                } else if (grid[row][col] == 'E'){
                    ++count_so_far;
                } else { // reset the count_so_farer
                    count_so_far = 0;
                }
            }
            count_so_far = 0;
            for (int row = NUM_OF_ROWS - 1; row >= 0; --row){
                if (grid[row][col] == '0'){
                    dp[row][col] += count_so_far;
                } else if (grid[row][col] == 'E'){
                    ++count_so_far;
                } else {
                    count_so_far = 0;
                }
            }
        }
        return find_max_value(dp);
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

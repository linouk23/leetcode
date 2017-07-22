// 296. Best Meeting Point - https://leetcode.com/problems/best-meeting-point

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Find the median value on both axises.
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        if (n == 0) { return 0; }
        int m = (int)grid[0].size();
        int result = 0;
        vector<int> posR, posC;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (grid[row][col] == 1) {
                    posR.emplace_back(row);
                    posC.emplace_back(col);
                }
            }
        }
        // posR is already sorted because of outer for loop
        int medianR = posR[posR.size() / 2];
        nth_element(posC.begin(), posC.begin() +  posC.size() / 2, posC.end());
        int medianC = posC[posC.size() / 2];
        for (int pos : posR) {
            result += abs(pos - medianR);
        }
        for (int pos : posC) {
            result += abs(pos - medianC);
        }
        return result;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

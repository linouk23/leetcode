// 546. Remove Boxes - https://leetcode.com/problems/remove-boxes

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Trick:
// Add the 3rd parameter to "burst balloons" problem.

class Solution {
private:
    // Let memo[L][R][K] be the max amount of points to get
    // on [L, R] segment by removing boxes and there're K
    // preceding boxes such that
    // boxes[L] = boxes[L - 1] = ... = boxes[L - K]
    // unordered_map<int, unordered_map<int, unordered_map<int, int>>> memo;
    static const int MAXN = 100;
    int rec(int L, int R, int K, vector<int> &colors, int memo[100][100][100]) {
        // Base cases:
        if (L == R) { return (K + 1) * (K + 1); }
        if (R == L - 1) { return 0; }
        if (memo[L][R][K]) { return memo[L][R][K]; }
        // Burst the Lth box:
        int result = (K + 1) * (K + 1) + rec(L + 1, R, 0, colors, memo);
        
        // Attach the Lth box to some Mth box (color[M] == color[L]),
        // so there're 1 + K preceding boxes with the same color to the
        // Mth box.
        for (int M = L + 1; M <= R; ++M) {
            if (colors[M] != colors[L]) { continue; }
            result = max(result,
                         rec(L + 1, M - 1, 0, colors, memo) +
                         rec(M, R, 1 + K, colors, memo));
        }
        memo[L][R][K] = result;
        return result;
    }
public:
    int removeBoxes(vector<int> boxes) {
        int memo[MAXN][MAXN][MAXN] = {0};
        int n = (int)boxes.size();
        return rec(0, n - 1, 0, boxes, memo);
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(41, sol.removeBoxes({1,1,2,2,2,2,1,1,1}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

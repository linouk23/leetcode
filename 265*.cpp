// 265. Paint House II - https://leetcode.com/problems/paint-house-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    struct Pair {
        int val, color;
    };
    struct twoMin {
        Pair low, high;
    };
    twoMin findMin(const vector<vector<int>> &dp, int day, int k) {
        twoMin mins {{INT_MAX, -1}, {INT_MAX, -1}};
        for (int color = 1; color <= k; ++color) {
            if (dp[day][color] <= mins.low.val) {
                mins.high = mins.low;
                mins.low.val = dp[day][color];
                mins.low.color = color;
            } else if (dp[day][color] <= mins.high.val) {
                mins.high.val = dp[day][color];
                mins.high.color = color;
            }
        }
        return mins;
    }
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = (int)costs.size();
        if (n == 0) { return 0; }
        int k = (int)costs[0].size();
        // Let dp[k][c] be the min cost to paint the 1st k houses
        // such that the last (k'th) color has the color c.
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, INT_MAX));
        for (int color = 1; color <= k; ++color) {
            dp[0][color] = 0;
        }
        for (int day = 1; day <= n; ++day) {
            // There're only 2 cases: either prev color was C or not,
            // So we can use 2 mins to optimize from O(N K^2) to O(NK):
            // If the min used color C, then we can take second min that
            // used other color.
            auto mins = findMin(dp, day - 1, k);
            for (int color = 1; color <= k; ++color) {
                if (mins.low.color != color) {
                    // dp[day - 1][mins.low.color] = mins.low.val 
                    dp[day][color] = dp[day - 1][mins.low.color] +
                                     costs[day][color];
                } else {
                    dp[day][color] = dp[day - 1][mins.high.color] +
                                     costs[day][color];
                }
            }
        }
        int result = INT_MAX;
        for (int color = 1; color <= k; ++color) {
            result = min(result, dp[n][color]);
        }
        return result;
    }
};


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

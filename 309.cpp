// 309. Best Time to Buy and Sell Stock with Cooldown - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> prices) {
        const int SKIP  = 0;
        const int BUY   = 1;
        const int SELL  = 2;
        
        const int EMPTY  = 0;
        const int FULL   = 1;
        if (prices.empty()) { return 0; }
        int n = (int)prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (3,
                                       vector<int> (2, INT_MIN)));
        // Trick.
        // Let dp[i][j][k] be the max balance for the 1st i days,
        // there's action j on day i and
        // there's k stocks in the end of the day i.
        dp[0][SKIP][0] = 0;
        dp[0][BUY][1]  = -prices[0];
        for (int day = 1; day < n; ++day) {
            // cooldown
            dp[day][SKIP][EMPTY] = max(dp[day - 1][SKIP][EMPTY],
                                       dp[day - 1][SELL][EMPTY]);
            dp[day][SKIP][FULL]  = max(dp[day - 1][SKIP][FULL],
                                       dp[day - 1][BUY][FULL]);
            dp[day][BUY][FULL]   = dp[day - 1][SKIP][EMPTY] - prices[day];
            dp[day][SELL][EMPTY] = max(dp[day - 1][SKIP][FULL],
                                       dp[day - 1][BUY][FULL])
                                   + prices[day];
        }
        return max({
            dp[n - 1][SKIP][EMPTY], dp[n - 1][SKIP][FULL],
            dp[n - 1][BUY][FULL], dp[n - 1][SELL][EMPTY],
        });
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(3, sol.maxProfit({1, 2, 3, 0, 2}));
}

TEST(SolutionTest, Empty) {
    Solution sol;
    EXPECT_EQ(0, sol.maxProfit({}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

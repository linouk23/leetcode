// 188. Best Time to Buy and Sell Stock IV - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> prices) {
        if (prices.empty()) { return 0; }
        int n = (int)prices.size();
        k = min(k, n);
        vector<vector<int>> dp(n, vector<int> (k + 1, 0));
        // dp[days][0] - 0 transactions
        // dp[0][num_of_compl_tr] = num_of_tr * (prices[0] - prices[0]) = 0
        for (int day = 1; day < n; ++day) {
            for (int num_of_compl_tr = 1; num_of_compl_tr <= k; ++num_of_compl_tr) {
                // Either don't make a transaction
                dp[day][num_of_compl_tr] = dp[day - 1][num_of_compl_tr];
                
                // Or sell on this day -> find the best day before to buy
                int val = INT_MIN;
                for (int buy_day = 0; buy_day < day; ++buy_day) {
                    val = max(val,
                              (prices[day] - prices[buy_day]) +
                              dp[buy_day][num_of_compl_tr - 1]);
                }
                dp[day][num_of_compl_tr] = max(dp[day][num_of_compl_tr],
                                               val);
            }
        }
        return dp[n - 1][k];
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(10, sol.maxProfit(3, {2,5,7,1,4,3,1,3}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

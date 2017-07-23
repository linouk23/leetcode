// 568. Maximum Vacation Days - https://leetcode.com/problems/maximum-vacation-days

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    int get_days(int day, int city, vector<vector<int>> days) {
        return days[city - 1][day - 1];
    }
public:
    int maxVacationDays(vector<vector<int>> fl, vector<vector<int>> days) {
        unordered_map<int, unordered_set<int>> g;
        // Reversed flights.
        int n = (int)fl.size();
        for (int from = 0; from < n; ++from) {
            for (int to = 0; to < n; ++to) {
                if (fl[from][to]) { g[to + 1].insert(from + 1); }
            }
        }
        int m = (int)days[0].size();
        // Let dp[k][c] be the answer (max vacation days)
        // for first k days and the last city is c.
        vector<vector<int>> dp(m + 10, vector<int> (n + 10, INT_MIN));
        // We can only start from city №1
        int start_city = 1;
        dp[0][start_city] = 0;
        for (int day = 1; day <= m; ++day) {
            for (int city = 1; city <= n; ++city) {
                // Either don't flight and stay in our current city
                dp[day][city] = dp[day - 1][city];
                // Or we just landed from somewhere
                for (int departure : g[city]) {
                    dp[day][city] = max(dp[day][city],
                                        dp[day - 1][departure]);
                }
                dp[day][city] += get_days(day, city, days);
            }
        }
        int result = 0;
        for (int city = 1; city <= n; ++city) {
            result = max(result, dp[m][city]);
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(12, sol.maxVacationDays({{0,1,1},{1,0,1},{1,1,0}},
                                      {{1,3,1},{6,0,3},{3,3,3}}));
    EXPECT_EQ(3, sol.maxVacationDays({{0,0,0},{0,0,0},{0,0,0}},
                                      {{1,1,1},{7,7,7},{7,7,7}}));
    EXPECT_EQ(21, sol.maxVacationDays({{0,1,1},{1,0,1},{1,1,0}},
                                      {{7,0,0},{0,7,0},{0,0,7}}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

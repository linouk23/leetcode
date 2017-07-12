// 256. Paint House - https://leetcode.com/problems/paint-house

#include "bits/stdc++.h"

using namespace std;

// There are a row of n houses, each house can be painted with one of
// the three colors: red, blue or green.
// The cost of painting each house with a certain color is different.
// You have to paint all the houses such that no two adjacent houses
// have the same color.
// The cost of painting each house with a certain color is represented by
// a n x 3 cost matrix. For example, costs[0][0] is the cost of painting
// house 0 with color red; costs[1][2] is the cost of painting house 1
// with color green, and so on...
// Find the minimum cost to paint all houses.

class Solution {
public:
    int minCost(vector<vector<int>> & costs) {
        if (costs.empty()) { return 0; }
        int n = (int)costs.size();
        // Let dp[k][c] be the min cost to paint the 1st k houses
        // such that the last (k'th) color has the color c.
        vector<vector<int>> dp(n + 1, vector<int> (3, INT_MAX));
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for (int idx = 0; idx < n; ++idx) {
            auto prices = costs[idx];
            int k = idx + 1;
            
            dp[k][0] = min(dp[k - 1][1], dp[k - 1][2]) + costs[k][0];
            dp[k][1] = min(dp[k - 1][0], dp[k - 1][2]) + costs[k][1];
            dp[k][2] = min(dp[k - 1][0], dp[k - 1][1]) + costs[k][2];
        }
        return min({dp[n][0], dp[n][1], dp[n][2]});
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

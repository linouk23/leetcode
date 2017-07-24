// 646. Maximum Length of Pair Chain - https://leetcode.com/problems/maximum-length-of-pair-chain

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Idea: greedy will work fine, this is equivalent to interval scheduling problem.
class Solution {
private:
    int bs(vector<vector<int>> &dp, int cur, vector<vector<int>>& pairs) {
        vector<int> candidate = pairs[cur];
        int L = -1, R = (int)pairs.size() + 1;
        // 1110000
        // find the leftmost position such that
        // x > arr[pos] => arr[pos + 1] = x
        // first 0 -> R
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (candidate[0] > dp[M][1]) {
                L = M;
            } else {
                R = M;
            }
        }
        return R;
    }
public:
    int findLongestChain(vector<vector<int>> pairs) {
        sort(pairs.begin(), pairs.end(),
             [](const vector<int> &p1, const vector<int> &p2) {
                 if (p1[1] == p2[1]) {
                     return p1[0] < p2[0];
                 }
                 return p1[1] < p2[1];
             });
        int n = (int)pairs.size();
        vector<vector<int>> dp(n + 1, {INT_MAX, INT_MAX});
        dp[0] = {INT_MIN, INT_MIN};
        for (int idx = 0; idx < n; ++idx) {
            int len = bs(dp, idx, pairs);
            if (dp[len][1] > pairs[idx][1]) {
                dp[len] = pairs[idx];
            }
        }
        for (int len = n; len >= 1; --len) {
            if (dp[len][0] != INT_MAX) {
                return len;
            }
        }
        return 0;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(2, sol.findLongestChain({{1,2}, {2,3}, {3,4}}));
    EXPECT_EQ(4, sol.findLongestChain({{-10,-8},{8,9},{-5,0},
                                       {6,10},{-6,-4},{1,7},
                                       {9,10},{-4,7}}));
    EXPECT_EQ(5, sol.findLongestChain({{9,10},{9,10},{4,5},
                                       {-9,-3},{-9,1},{0,3},
                                       {6,10},{-5,-4},{-7,-6}}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// 514. Freedom Trail - https://leetcode.com/problems/freedom-trail

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    int dist(int idx, int center, int n) {
        int diff = abs(idx - center);
        return min(diff, n - diff);
    }
public:
    int findRotateSteps(string ring, string key) {
        if (key.empty()) { return 0; }
        const int INF = (int)1e9;
        int n = (int)ring.length();
        int m = (int)key.length();
        unordered_map<char, vector<int>> chToInd;
        for (int idx = 0; idx < n; ++idx) {
            char ch = ring[idx];
            chToInd[ch].emplace_back(idx);
        }
        // Let dp[K][finish_idx] be the minimum number of steps
        // in order to spell first K the characters in the keyword
        // so that the idx for the last letter is finish_idx
        // (ch = ring[finish_idx] is aligned at 12:00 direction).
        vector<vector<int>> dp(m + 1, vector<int> (n, INF));
        // Base case.
        int last_idx = 0;
        dp[0][0] = 0;
        
        for (int len = 1; len <= m; ++len) {
            char ch = key[len - 1];
            for (int idx = 0; idx < n; ++idx) {
                for (int last_idx : chToInd[ch]) {
                    dp[len][last_idx] = min(dp[len][last_idx],
                                            dp[len - 1][idx] + dist(idx, last_idx, n));
                }
            }
        }
        int result = INT_MAX;
        char last_letter = key.back();
        for (int idx : chToInd[last_letter]) {
            result = min(result, dp[m][idx]);
        }
        return result + (int)key.length();
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(4, sol.findRotateSteps("godding", "gd"));
    EXPECT_EQ(10, sol.findRotateSteps("edcba", "abcde"));
}

TEST(SolutionTest, Empty) {
    Solution sol;
    EXPECT_EQ(0, sol.findRotateSteps("godding", ""));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

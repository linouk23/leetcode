// 629. K Inverse Pairs Array - https://leetcode.com/problems/k-inverse-pairs-array

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

typedef long long ll;

class Solution {
private:
    static const ll mod = (ll)1e9 + 7;
public:
    int kInversePairs(int N, int K) {
        if (K > N * (N - 1) / 2 || K < 0)   { return 0; }
        if (K == 0 || K == N * (N - 1) / 2) { return 1; }
        vector<vector<ll>> dp(N + 10, vector<ll> (K + 10, 0));
        // 1
        dp[1][0] = 1;
        // 12, 21
        dp[2][0] = 1;
        dp[2][1] = 1;
        for (int n = 3; n <= N; ++n) {
            for (int k = 0; k <= K; ++k) {
                if (k > 0) {
                    dp[n][k] += dp[n][k - 1];
                    dp[n][k] %= mod;
                }
                dp[n][k] += dp[n - 1][k];
                dp[n][k] %= mod;
                if (k < n) { continue; }
                dp[n][k] -= dp[n - 1][k - n];
                dp[n][k] += mod;
                dp[n][k] %= mod;
            }
        }
        return (int)dp[N][K];
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(1, sol.kInversePairs(3, 3));
    EXPECT_EQ(2, sol.kInversePairs(3, 1));
    EXPECT_EQ(1, sol.kInversePairs(3, 0));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

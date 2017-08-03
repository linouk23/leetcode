// 651. 4 Keys Keyboard - https://leetcode.com/problems/4-keys-keyboard

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int maxA(int N) {
        vector<int> dp (N + 10);
        // ops -> max len
        dp[0] = 0;
        for (int ops = 1; ops <= N; ++ops) {
            // Write 'A'
            dp[ops] = dp[ops - 1] + 1;
            // Find a breakpoint and use ctrl + A + C + V all the way
            for (int breakpoint = 3; ops - breakpoint >= 0; ++breakpoint) {
                dp[ops] = max(dp[ops],
                              dp[ops - breakpoint] * (breakpoint - 1));
                // break = 3 -> * 1 (insert: 3 op) + len
                // => 3 * (1 + 1)
                // break = 4 -> * 2 (insert: 3 op + reuse the buffer: 1 op) + len
                // => 4 * (2 + 1)
            }
        }
        return dp[N];
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(3, sol.maxA(3));
    EXPECT_EQ(9, sol.maxA(7));
    EXPECT_EQ(16, sol.maxA(9));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

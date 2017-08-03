// 650. 2 Keys Keyboard - https://leetcode.com/problems/2-keys-keyboard

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Trick:
/*
It takes 2 ops to double, 3 ops to triple, ...
if n % 2 == 0, then f(n) = f(n/2) + 2
if n % 3 == 0, then f(n) = f(n/3) + 3
2 * 2 = f(4) = 2 + 2,
2 * 3 > f(6) = f(2) + 3 = 2 + 3,
4 * 4 > f(16) = f(4) + 4 = 4 + 4,
so it is always better to divide whenever possible.
*/

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp (n + 10);
        // len -> steps
        dp[1] = 0;
        for (int len = 2; len <= n; ++len) {
            dp[len] = len; // Copy 1 and paste all the way
            for (int ops = len - 1; ops > 1; --ops) {
                if (len % ops == 0) {
                    dp[len] = dp[ops] + (len / ops);
                    break;
                }
            }
        }
        return dp[n];
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(3, sol.minSteps(3));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

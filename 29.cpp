// 29. Divide Two Integers - https://leetcode.com/problems/divide-two-integers

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

typedef long long ll;

// Idea: Suppose we want to divide 15 by 3, so 15 is dividend
// and 3 is divisor. Well, division simply requires us to find
// how many times we can subtract the divisor from the the dividend
// without making the dividend negative.
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        bool is_minus = ((dividend < 0) ^ (divisor < 0));
        ll x = dividend;
        ll y = divisor;
        // x / y -> (x - y) / y
        int k = 32;
        x = abs(x); y = abs(y);

        ll result = 0;
        while (x >= y) {
            while ((y << k) > x) {
                k -= 1;
            }
            x -= (y << k);
            result += (1 << k);
        }
        return is_minus ? -(int)result : (int)result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(2, sol.divide(4, 2));
    EXPECT_EQ(2, sol.divide(5, 2));
    EXPECT_EQ(7, sol.divide(7, 1));
    EXPECT_EQ(-1, sol.divide(-1, 1));
    EXPECT_EQ(-1, sol.divide(1, -1));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

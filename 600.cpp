// 600. Non-negative Integers without Consecutive Ones - https://leetcode.com/problems/non-negative-integers-without-consecutive-ones

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    static const int NUM_OF_BITS = 32;
public:
    int findIntegers(int num) {
        // Let dp[N] be the total number of numbers,
        // without consec ones
        vector<int> dp(NUM_OF_BITS);
        dp[0] = 1, dp[1] = 2;
        for (int len = 2; len < NUM_OF_BITS; ++len) {
            dp[len] = dp[len - 1] + dp[len - 2];
        }
        // Use prev to track 2 conseq ones.
        // 101 - 5
        // 110 - 5
        // 111 - 5
        int result = 0, prev = 0;
        bitset<NUM_OF_BITS> b(num);
        for (int k = NUM_OF_BITS - 1; k >= 0; --k) {
            if (b[k]) {
                // b[k] = 0 -> there's 0 + k bits to the right
                // => result += dp[k]
                // If we find a '1' with k digits to the right, 
                // count increases by dp(k) because we can put a '0' at this digit
                // and any valid length k string behind;
                result += dp[k];
                if (prev) { return result; }
            }
            // After that, we continue the loop to 
            // consider the remaining cases, i.e., we put a '1' at this digit.
            prev = b[k];
        }
        return result + 1;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(5, sol.findIntegers(5));
    EXPECT_EQ(2, sol.findIntegers(1));
    EXPECT_EQ(3, sol.findIntegers(2));
    EXPECT_EQ(4, sol.findIntegers(4));
    EXPECT_EQ(8, sol.findIntegers(11));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// https://discuss.leetcode.com/topic/90639/c-non-dp-o-32-fibonacci-solution
// Scan the number from most significant digit, 
// i.e. left to right, in binary format.
// If we find a '1' with k digits to the right, 
// count increases by dp(k) because we can put a '0' at this digit
// and any valid length k string behind; After that, we continue the loop to 
// consider the remaining cases, i.e., we put a '1' at this digit. If consecutive 
// 1s are found, we exit the loop and return the answer. By the end of the loop, 
// we return count+1 to include the number n itself.

// For example, if n is 10010110,
// we find first '1' at 7 digits to the right, we add range 00000000-01111111, 
// which is f(7);
// second '1' at 4 digits to the right, add range 10000000-10001111, f(4);
// third '1' at 2 digits to the right, add range 10010000-10010011, f(2);
// fourth '1' at 1 digits to the right, add range 10010100-10010101, f(1);
// Those ranges are continuous from 00000000 to 10010101. And any greater number <= n will have consecutive 1.

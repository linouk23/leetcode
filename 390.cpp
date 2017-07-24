// 390. Elimination Game - https://leetcode.com/problems/elimination-game

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Credits to
// https://discuss.leetcode.com/topic/59293/java-easiest-solution-o-logn-with-explanation

class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int remaining = n;
        bool startFromLeft = true;
        int step = 1;
        while (remaining > 1) {
            if (startFromLeft || remaining % 2) {
                head += step;
            }
            startFromLeft = !startFromLeft;
            remaining /= 2;
            step *= 2;
        }
        return head;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(6, sol.lastRemaining(9));
    EXPECT_EQ(14, sol.lastRemaining(24));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

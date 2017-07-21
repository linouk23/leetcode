// 464. Can I Win - https://leetcode.com/problems/can-i-win

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    unordered_map<int, bool> memo;
    // total >= target => cur pos is L -> return false
    // exists edge to L -> current position is W
    // !(exists edge to L) == every edge to W -> current position is L
    // canGetIntoLosingPosition == canIWin
    bool canIWin(int used, int maxInt, int total, int target) {
        if (memo.count(used)) { return memo[used]; }
        if (total >= target) { return false; }
        bool result = false;
        for (int idx = maxInt - 1; idx >= 0; --idx) {
            if (used & (1 << idx)) { continue; }
            used = used ^ (1 << idx); // push_back
            int usedNum = idx + 1;
            if (!canIWin(used, maxInt, total + usedNum, target)) {
                result = true;
                // Dangerous mistake:
                // break;
            }
            used = used ^ (1 << idx); // pop_back
            if (result) { break; }
        }
        memo[used] = result;
        return memo[used];
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int used = 0;
        int maxSum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (maxSum < desiredTotal) { return false; }
        if (desiredTotal <= 0) { return true; }
        return canIWin(used,maxChoosableInteger, 0, desiredTotal);
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_TRUE(sol.canIWin(3, 5));
    EXPECT_FALSE(sol.canIWin(10, 11));
    EXPECT_TRUE(sol.canIWin(10, 0));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

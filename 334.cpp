// 334. Increasing Triplet Subsequence - https://leetcode.com/problems/increasing-triplet-subsequence

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int> nums) {
    //    {min1 <= min2 <= min3}
    //    LIS O(N logN)
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int num : nums) {
            if (num <= min1) {
                min1 = num;
            } else if (num <= min2) {
                min2 = num;
            } else {
                return true;
            }
        }
        return false;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_TRUE(sol.increasingTriplet({1,2,3}));
    EXPECT_TRUE(sol.increasingTriplet({1,2,1,1,3}));
    EXPECT_FALSE(sol.increasingTriplet({1,2,2}));
    EXPECT_FALSE(sol.increasingTriplet({3}));
}

TEST(SolutionTest, Empty) {
    Solution sol;
    EXPECT_FALSE(sol.increasingTriplet({}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

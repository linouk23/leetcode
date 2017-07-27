// 330. Patching Array - https://leetcode.com/problems/patching-array

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int minPatches(vector<int> nums, int n) {
        // Trick: from EPI
        // Can construct up to [0, fstMiss)
        long long fstMiss = 1, result = 0, idx = 0;
        int m = (int)nums.size();
        while (fstMiss <= n) {
            if (idx < m && nums[idx] <= fstMiss) {
                fstMiss += nums[idx];
                idx += 1;
            } else {
                fstMiss += fstMiss;
                result += 1;
            }
        }
        return (int)result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(0, sol.minPatches({1,2,2}, 5));
    EXPECT_EQ(2, sol.minPatches({1,5,10}, 20));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

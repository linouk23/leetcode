// 209. Minimum Size Subarray Sum - https://leetcode.com/problems/minimum-size-subarray-sum

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int> nums) {
        int L = 0, R = 0;
        int n = (int)nums.size();
        struct Result {
            int sum, len;
        } result {0, INT_MAX};
        while (R < n) {
            result.sum += nums[R];
            while (result.sum >= s) {
                result.len = min(result.len, R - L + 1);
                result.sum -= nums[L];
                L += 1;
            }
            ++R;
        }
        return result.len == INT_MAX ? 0 : result.len;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(2, sol.minSubArrayLen(7, {2,3,1,2,4,3}));
    EXPECT_EQ(1, sol.minSubArrayLen(7, {2,3,1,27,4,3}));
    EXPECT_EQ(0, sol.minSubArrayLen(3, {1,1}));
}

TEST(SolutionTest, Empty) {
    Solution sol;
    EXPECT_EQ(0, sol.minSubArrayLen(7, {}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// 523. Continuous Subarray Sum - https://leetcode.com/problems/continuous-subarray-sum

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int> nums, int k) {
        // Have to use pre because the required length is at least 2
        int n = (int)nums.size(), sum_so_far = 0;
        unordered_map<int, int> mods;
        mods[0] = 0;
        for (int idx = 0; idx < n; ++idx) {
            sum_so_far += nums[idx];
            int mod = (k == 0) ? sum_so_far : sum_so_far % k;
            // sum[:L] % k = q
            // sum[:R] % k = q -> sum(L:R] % k = 0 (think about clock)
            if (mods.count(mod)) {
                // idx + 1 because of prefix sum map
                // (prefix[0] = 0, and then prefix[idx] = sum[0:idx - 1]
                // idx from 1...n
                if (idx + 1 - mods[mod] > 1) { return true; }
            } else {
                mods[mod] = idx + 1;
            }
        }
        return false;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    // 23 % 6 == 29 % 6 == 5 -> [2,4] % 6 == 0
    EXPECT_TRUE(sol.checkSubarraySum({23, 2, 4, 6, 7}, 6));
    EXPECT_TRUE(sol.checkSubarraySum({23, 2, 6, 4, 7}, 6));
}

TEST(SolutionTest, Empty) {
    Solution sol;
    EXPECT_FALSE(sol.checkSubarraySum({}, 6));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

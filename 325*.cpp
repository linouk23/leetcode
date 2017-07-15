// 325. Maximum Size Subarray Sum Equals k - https://leetcode.com/problems/maximum-size-subarray-sum-equals-k

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int> nums, int k) {
        unordered_map<int, int> prefix;
        // Trick.
        prefix[0] = -1;
        int result = 0;
        
        int sum_so_far = 0;
        for (int idx = 0; idx < (int)nums.size(); ++idx) {
            sum_so_far += nums[idx];
            if (prefix.count(sum_so_far - k)) {
                result = max(result, idx - prefix[sum_so_far - k]);
            }
            if (prefix.count(sum_so_far)) { continue; }
            
            // Trick.
            // Store the earliest match to maximize the len of subarray.
            prefix[sum_so_far] = idx;
        }
        
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(4, sol.maxSubArrayLen({1, -1, 5, -2, 3}, 3));
    EXPECT_EQ(2, sol.maxSubArrayLen({-2, -1, 2, 1}, 1));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

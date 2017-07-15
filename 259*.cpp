// 259. 3Sum Smaller - https://leetcode.com/problems/3sum-smaller

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int result = 0;
        for (int idx = 0; idx < n; ++idx) {
            int L = idx + 1;
            int R = n - 1;
            while (L < R) {
                int sum = nums[idx] + nums[L] + nums[R];
                if (sum < target) {
                    // target = 10
                    // _1 _3 4 8 _16
                    // _1 _3 4 _8 16
                    // => |(1 3 8), (1 3 4)| = 2
                    result += (R - L);
                    ++L;
                } else {
                    --R;
                }
            }
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(2, sol.threeSumSmaller({-2, 0, 1, 3}, 2));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

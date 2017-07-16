// 611. Valid Triangle Number - https://leetcode.com/problems/valid-triangle-number

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Idea: 3 sum smaller
class Solution {
public:
    int triangleNumber(vector<int> nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int result = 0;
        for (int idx = n - 1; idx >= 0; --idx) {
            int L = 0;
            int R = idx - 1;
            while (L < R) {
                if (nums[L] + nums[R] > nums[idx]) {
                    result += R - L;
                    //            L       R   idx
                    // Trick: 1 3 _5 6 8 _15 _19
                    // (5, 6, 8) + 15 > 19
                    // --R -> ??? + 8 > 19
                    --R;
                } else {
                    ++L;
                }
            }
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(3, sol.triangleNumber({2,2,3,4}));
}


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

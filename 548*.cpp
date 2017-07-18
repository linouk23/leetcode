// 548. Split Array with Equal Sum - https://leetcode.com/problems/split-array-with-equal-sum

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// https://discuss.leetcode.com/topic/85026/simple-java-solution-o-n-2
// Idea:
// Iterate middle cuts and then find left cuts which
// divides the first half into two equal quarters, store
// that quarter sums in the hashset. Then find right cuts
// which divides the second half into two equal quarters and
// check if quarter sum is present in the hashset. If yes return true.
class Solution {
public:
    bool splitArray (vector<int> nums) {
        int n = (int)nums.size();
        if (n < 7) { return false; }
        vector<int> prefix(n + 1, 0);
        for (int idx = 0; idx < n; ++idx) {
            prefix[idx + 1] = prefix[idx] + nums[idx];
        }
        for (int M = 4; M <= n - 3; ++M) {
            unordered_set<int> quarter_sum;
            for (int L = 1; L < M - 1; ++L) {
                if (prefix[L - 1] == prefix[M - 1] - prefix[L])
                    quarter_sum.insert(prefix[L - 1]);
            }
            for (int R = M + 1; R < n; ++R) {
                if ((prefix[R - 1] - prefix[M] == prefix[n] - prefix[R]) &&
                    quarter_sum.count(prefix[R - 1] - prefix[M])) {
                    return true;
                }
                
            }
        }
        return false;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_TRUE(sol.splitArray({1,2,1,2,1,2,1}));
    EXPECT_FALSE(sol.splitArray({1,1,1,1,1,1,1,1,1}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

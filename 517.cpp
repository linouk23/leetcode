// 517. Super Washing Machines - https://leetcode.com/problems/super-washing-machines

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// https://discuss.leetcode.com/topic/79923/c-16ms-o-n-solution-with-trivial-proof

// For a single machine, necessary operations is to transfer
// dresses from one side to another until sum of both sides and
// itself reaches the average number. We can calculate
// (required dresses) - (contained dresses) of each side as L and R:

class Solution {
public:
    int findMinMoves(vector<int> machines) {
        int len = (int)machines.size();
        vector<int> sum(len + 1, 0);
        for (int idx = 0; idx < len; ++idx) {
            sum[idx + 1] = sum[idx] + machines[idx];
        }
        
        // Check the sum of dresses in all machines.
        // If that number cannot be divided by count of machines,
        // there is no solution.
        if (sum[len] % len) { return -1; }
        
        int avg = sum[len] / len;
        int result = 0;
        for (int idx = 0; idx < len; ++idx)
        {
            int L = idx * avg - sum[idx];
            int R = (len - idx - 1) * avg -
                    (sum[len] - sum[idx] - machines[idx]);
            
            if (L > 0 && R > 0) {
                result = max(result, L + R);
            } else {
                result = max(result, max(abs(L), abs(R)));
            }
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(3, sol.findMinMoves({1,0,5}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

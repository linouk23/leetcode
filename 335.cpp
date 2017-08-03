// 335. Self Crossing - https://leetcode.com/problems/self-crossing

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int> v) {
        v.insert(v.begin(), 4, 0);
        
        int len = (int)v.size();
        int idx = 4;
        
        // Outer spiral.
        while (idx < len && v[idx] > v[idx - 2]) { idx += 1; }
        
        if (idx == len) { return false; }
        
        // Check border.
        if (v[idx] >= v[idx - 2] - v[idx - 4]) {
            v[idx - 1] -= v[idx - 3];
        }
        
        // Inner spiral.
        idx += 1;
        while (idx < len && v[idx] < v[idx - 2]) { idx += 1; }
        
        return idx != len;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_TRUE(sol.isSelfCrossing({1,1,1,1}));
    EXPECT_FALSE(sol.isSelfCrossing({1,2,3,4}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

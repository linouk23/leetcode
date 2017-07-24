// 452. Minimum Number of Arrows to Burst Balloons - https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// https://discuss.leetcode.com/topic/73981/share-my-explained-greedy-solution-as-the-highest-voted-java-solution-right-now-is-not-ideal

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>> points) {
        if (points.empty()) { return 0; }
        // Sort the balloons by their ending position.
        sort(points.begin(), points.end(), [](const pair<int, int>& x, const pair<int, int>& y) { return x.second < y.second; });
        int arrowPos = points[0].second;
        int result = 1;
        for (int idx = 1; idx < (int)points.size(); ++idx) {
            if (arrowPos >= points[idx].first) {
                continue;
            }
            result += 1;
            arrowPos = points[idx].second;
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(2, sol.findMinArrowShots({{10,16}, {2,8}, {1,6}, {7,12}}));
    EXPECT_EQ(2, sol.findMinArrowShots({{1,9},{7,16},{2,5},{7,12},{9,11},{2,10},{9,16},{3,9},{1,3}}));
    EXPECT_EQ(3, sol.findMinArrowShots({{0,9},{1,8},{7,8},{1,6},{9,16},{7,13},{7,10},{6,11},{6,9},{9,13}}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

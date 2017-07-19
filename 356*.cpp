// 356. Line Reflection - https://leetcode.com/problems/line-reflection

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Idea:
// Find the smallest and largest x-value for all points.
// If there is a line then it should be at y = (minX + maxX) / 2.
// For each point, make sure that it has a reflected point in the opposite side.
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        unordered_map<int, set<int>> m;
        int mx = INT_MIN, mn = INT_MAX;
        for (auto a : points) {
            mx = max(mx, a.first);
            mn = min(mn, a.first);
            m[a.first].insert(a.second);
        }
        double y = (double)(mx + mn) / 2;
        for (auto p : points) {
            int t = 2 * y - p.first;
            if (!m.count(t) || !m[t].count(p.second)) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

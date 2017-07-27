// 218. The Skyline Problem - https://leetcode.com/problems/the-skyline-problem

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct MyPoint {
    bool isStart;
    int x, height;
    
    bool operator<(const MyPoint & that) const {
        if (x != that.x) { return x < that.x; }
        // both starts: the higher start should be before
        if (isStart && that.isStart) {
            return height > that.height;
        }
        // both ends: the lower end should be before
        if (!isStart && !that.isStart) {
            return height < that.height;
        }
        // start && finish: start should be before
        return isStart;
    }
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> buildings) {
        vector<pair<int, int>> result;
        vector<MyPoint> points;
        for (const auto &b : buildings) {
            int left = b[0], right = b[1], height = b[2];
            points.push_back({true, left, height});
            points.push_back({false, right, height});
        }
        sort(points.begin(), points.end());
        // height - count
        map<int, int> countTable;
        // Add origin fake point
        countTable[0] = 1;
        int prevMax = 0;
        for (const auto &p : points) {
            if (p.isStart) {
                countTable[p.height] += 1;
            } else { // Finish
                countTable[p.height] -= 1;
                if (countTable[p.height] == 0) {
                    countTable.erase(p.height);
                }
            }
            int curMax = countTable.rbegin()->first;
            if (prevMax != curMax) {
                result.push_back({p.x, curMax});
            }
            prevMax = curMax;
        }
        return result;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

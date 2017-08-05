// 391. Perfect Rectangle - https://leetcode.com/problems/perfect-rectangle

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    string getKeyForPoint(int x, int y) {
        return to_string(x) + "#" + to_string(y);
    }
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.empty()) { return false; }
        int trX, trY, blX, blY;
        trX = trY = INT_MIN;
        blX = blY = INT_MAX;
        
        int area = 0;
        unordered_map<string, int> count;
        for (const auto &rec : rectangles) {
            trX = max(trX, rec[2]);
            trY = max(trY, rec[3]);
            blX = min(blX, rec[0]);
            blY = min(blY, rec[1]);
            area += (rec[2] - rec[0]) * (rec[3] - rec[1]);
            count[getKeyForPoint(rec[0], rec[1])] += 1;
            count[getKeyForPoint(rec[0], rec[3])] += 1;
            count[getKeyForPoint(rec[2], rec[1])] += 1;
            count[getKeyForPoint(rec[2], rec[3])] += 1;
        }
        unordered_set<string> points = {
            getKeyForPoint(trX, trY),
            getKeyForPoint(trX, blY),
            getKeyForPoint(blX, trY),
            getKeyForPoint(blX, blY),
        };
        for (const auto &p : count) {
            if (p.second % 2 && !points.count(p.first)) {
                return false;
            }
        }
        for (const auto &p : points) {
            if (count[p] != 1) {
                return false;
            }
        }
        return area == (trX - blX) * (trY - blY);
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

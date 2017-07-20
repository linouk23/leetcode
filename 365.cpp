// 365. Water and Jug Problem - https://leetcode.com/problems/water-and-jug-problem

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    int gcd(int a, int b) {
        if (b == 0) { return a; }
        return gcd(b, a % b);
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) { return false; }
        if (x == z || y == z || x + y == z ) { return true; }
        return z % gcd(x, y) == 0;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// 233. Number of Digit One - https://leetcode.com/problems/number-of-digit-one

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for (long long idx = 1; idx <= n; idx *= 10) {
            long long divider = idx * 10;
            count += (n / divider) * idx +
                      min(max(n % divider - idx + 1, 0LL), idx);
        }
        return count;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

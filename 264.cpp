// 264. Ugly Number II - https://leetcode.com/problems/ugly-number-ii

#include "bits/stdc++.h"

using namespace std;

// In order to produce a new smallest ugly number, one of (or some of) 2, 3, 5
// needs to multiply a smaller ugly number, and there come the pointers.
// After an ugly number is produced, the corresponding pointer(s) needs to move forward.
// Otherwise it will produce the same ugly number.
// And the order is retained since each product is larger or equal than before and we extract the minimum every time.

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) { return 0; }
        if (n == 1) { return 1; }
        vector<int> ugly_nums(n+10);
        ugly_nums[0] = 1;
        int p2, p3, p5;
        p2 = p3 = p5 = 0;
        for (int idx = 1; idx <= n - 1; ++idx) {
            // Trick.
            // ugly_nums[1] = min(ugly_nums[0] * 2, ugly_nums[0] * 3, ugly_nums[0] * 5)
            // If we don't change 'pointers', it'll produce the same ugly number.
            ugly_nums[idx] = min({ugly_nums[p2] * 2, ugly_nums[p3] * 3, ugly_nums[p5] * 5});
            
            // Because of 6:
            if (ugly_nums[idx] == ugly_nums[p2] * 2) { ++p2; }
            if (ugly_nums[idx] == ugly_nums[p3] * 3) { ++p3; }
            if (ugly_nums[idx] == ugly_nums[p5] * 5) { ++p5; }
        }
        return ugly_nums[n - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

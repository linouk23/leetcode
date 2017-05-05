// 343. Integer Break - https://leetcode.com/problems/integer-break

#include "bits/stdc++.h"

using namespace std;

// 6 = 2 + 2 + 2 = 3 + 3. But 2 * 2 * 2 < 3 * 3.
// Therefore, if there are three 2's in the decomposition,
// we can replace them by two 3's to gain a larger product.

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        if (n % 3 == 0) {
            return pow(3, n / 3);
        } else if (n % 3 == 2) {
            return pow(3, n / 3) * 2;
        } else {
            return pow(3, n / 3 - 1) * 4;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

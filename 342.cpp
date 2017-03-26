// 342. Power of Four - https://leetcode.com/problems/power-of-four

#include <bits/stdc++.h>

using namespace std;

// (4^n - 1) % 3 == 0.
// Proof:
// (1) 4^n - 1 = (2^n + 1) * (2^n - 1)
// (2) among any 3 consecutive numbers, there must be one that is a multiple of 3
// among (2^n-1), (2^n), (2^n+1), one of them must be a multiple of 3, and (2^n) 
// cannot be the one, therefore either (2^n-1) or (2^n+1) must be a multiple of 3,
// and 4^n-1 must be a multiple of 3 as well.
class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num >= 0) && ((num & (num -1)) == 0) && (--num % 3 == 0);
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.isPowerOfFour(16) == true);
    assert(solution.isPowerOfFour(1) == true);
    assert(solution.isPowerOfFour(4) == true);
    assert(solution.isPowerOfFour(3) == false);
    assert(solution.isPowerOfFour(17) == false);

    return 0;
}

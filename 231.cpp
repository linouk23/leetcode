// 231. Power of Two - https://leetcode.com/problems/power-of-two

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false; 
        }

        return n && (!(n & (n - 1)));
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.isPowerOfTwo(0) == false);
    assert(solution.isPowerOfTwo(1) == true);
    assert(solution.isPowerOfTwo(2) == true);
    assert(solution.isPowerOfTwo(8) == true);
    assert(solution.isPowerOfTwo(255) == false);
    assert(solution.isPowerOfTwo(INT_MAX) == false);
    assert(solution.isPowerOfTwo(INT_MIN) == false);

    return 0;
}

// 326. Power of Three - https://leetcode.com/problems/power-of-three

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n > 0 && (n % 3 == 0)) {
            n /= 3;
        }
        return n == 1;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.isPowerOfThree(3) == true);
    assert(solution.isPowerOfThree(5) == false);
    assert(solution.isPowerOfThree(INT_MAX) == false);
    assert(solution.isPowerOfThree(81) == true);

    return 0;
}

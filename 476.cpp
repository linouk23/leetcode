// 476. Number Complement - https://leetcode.com/problems/number-complement

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        if (num == 0) {
            return 1;
        }

        unsigned int mask = ~0;
        while(num & mask) {
            mask <<= 1;
        }

        return (~mask) & (~num);
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.findComplement(5) == 2);
    assert(solution.findComplement(1) == 0);
    assert(solution.findComplement(0) == 1);
    assert(solution.findComplement(INT_MAX) == 0);
    assert(solution.findComplement(INT_MIN) == INT_MAX);

    return 0;
}

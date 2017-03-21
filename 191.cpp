// 191. Number of 1 Bits - https://leetcode.com/problems/number-of-1-bits

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num_of_one_bits = 0;
        while(n) {
            num_of_one_bits += (n & 1);
            n /= 2;
        }
        return num_of_one_bits;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.hammingWeight(0) == 0);
    assert(solution.hammingWeight(2) == 1);
    assert(solution.hammingWeight(7) == 3);
    assert(solution.hammingWeight(256) == 1);

    return 0;
}

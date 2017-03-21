// 190. Reverse Bits - https://leetcode.com/problems/reverse-bits

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        const int num_of_bits = 32;
        for (int index = 0; index < num_of_bits; ++index) {
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.reverseBits(43261596) == 964176192);
    assert(solution.reverseBits(2147483648) == 1);

    return 0;
}

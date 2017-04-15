// 190. Reverse Bits - https://leetcode.com/problems/reverse-bits

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t num) {
        const int num_of_bits = 32;
        unsigned int reverse_num = 0;
        
        for (int index = 0; index < num_of_bits; ++index) {
            if (num & (1 << index)) {
                reverse_num |= (1 << (num_of_bits - index - 1));
            }
        }
        
        return reverse_num;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.reverseBits(43261596) == 964176192);
    assert(solution.reverseBits(2147483648) == 1);

    return 0;
}

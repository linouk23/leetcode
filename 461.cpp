// 461. Hamming Distance - https://leetcode.com/problems/hamming-distance

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        const int num_of_bits = 32;
        bitset<num_of_bits> fst_number(x);
        bitset<num_of_bits> snd_number(y);
        return (fst_number ^ snd_number).count();
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.hammingDistance(1, 4) == 2);
    assert(solution.hammingDistance(127, 0) == 7);
    assert(solution.hammingDistance(-123, -123) == 0);
    assert(solution.hammingDistance(0, 0) == 0);
    assert(solution.hammingDistance(INT_MAX, INT_MAX) == 0);
    
    return 0;
}

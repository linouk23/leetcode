// 260. Single Number III - https://leetcode.com/problems/single-number-iii

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_of_two_single_numbers = 0;
        for (int num : nums) {
            xor_of_two_single_numbers ^= num;
        }
        int last_one_bit = xor_of_two_single_numbers &
                           (~(xor_of_two_single_numbers - 1));
        int fst = 0, snd = 0;
        for (int num : nums) {
            if (num & last_one_bit) {
                fst ^= num;
            } else {
                snd ^= num;
            }
        }
        return {fst, snd};
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

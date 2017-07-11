// 137. Single Number II - https://leetcode.com/problems/single-number-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int pos = 0; pos < 32; ++pos) {
            int sum_of_bits = 0;
            for (int num : nums) {
                if (num & (1 << pos)) {
                    sum_of_bits++;
                }
            }
            if (sum_of_bits % 3) {
                result = result | (1 << pos);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

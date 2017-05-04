// 477. Total Hamming Distance - https://leetcode.com/problems/total-hamming-distance

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bit_count(32, 0);
        int result = 0;
        int n = (int)nums.size();
        for (int bit = 31; bit > 0; --bit) {
            for (int num : nums) {
                bit_count[bit] += (num & (1 << (31 - bit))) ? 1 : 0;
            }
            int num_of_zeroes = n - bit_count[bit];
            int num_of_ones = bit_count[bit];
            result += num_of_ones * num_of_zeroes;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

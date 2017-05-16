// 400. Nth Digit - https://leetcode.com/problems/nth-digit

#include "bits/stdc++.h"

using namespace std;

// Find the length of the number where the nth digit is from;
// Find the actual number where the nth digit is from;
// Find the nth digit and return.

class Solution {
public:
    int findNthDigit(int n) {
        long long cur_len = 1;
        long long num_of_numbers_with_cur_len = 9;
        long long start = 1;
        --n;
        while (n > cur_len * num_of_numbers_with_cur_len) {
            n -= cur_len * num_of_numbers_with_cur_len;
            cur_len += 1;
            num_of_numbers_with_cur_len *= 10;
            start *= 10;
        }
        start += n / cur_len;
        string actual_num = to_string(start);
        return actual_num[n % cur_len] - '0';
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
// 625. Minimum Factorization - https://leetcode.com/problems/minimum-factorization

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;


// Case 1: n < 10 When n is smaller than n,
// the output is always n+10. For example
// for n = 7, output is 17. For n = 9, output is 19.

// Case 2: n >= 10: Find all factors of n which are between 2 and 9 (both inclusive).
// The idea is to start searching from 9 so that the number of digits in result are 
// minimized. For example 9 is preferred over 33 and 8 is preferred over 24.
// Store all found factors in an array. The array would contain digits in 
// non-increasing order, so finally print the array in reverse order.
class Solution {
public:
    int smallestFactorization(int num) {
        if (num < 2) { return num; }
        long long result = 0;
        for (int idx = 9, d = 0; idx >= 2 && d < 10; --idx) {
            while (num % idx == 0 && d < 10) {
                result += idx * pow(10, d++);
                num /= idx;
            }
        }
        return num > 1 || result > INT_MAX ? 0 : (int)result;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// 479. Largest Palindrome Product - https://leetcode.com/problems/largest-palindrome-product

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) { return 9; }
        // if n = 3 then upper = 999 and lower = 99
        ll upper = (ll)pow(10, n) - 1LL;
        ll lower = upper / 10;
        ll max_num = upper * upper;
        // represents the first half of the maximum assumed palindrom.
        // e.g. if n = 3 then max_num = 999 x 999 = 998001
        // so half1 = 998
        ll half1 = max_num / (ll)pow(10, n);
        bool has_found = false;
        ll palindrom = 0;
        
        while (!has_found) {
            // Creates maximum assumed palindrom
            // e.g. if n = 3 first time the maximum
            // assumed palindrom will be 998 899
            auto half2 = to_string(half1);
            reverse(half2.begin(), half2.end());
            palindrom = stoll(to_string(half1) + half2);
            for (ll divisor = upper; divisor * divisor >= palindrom; --divisor) {
                if (palindrom % divisor == 0) { return (int)(palindrom % 1337); }
            }
            --half1;
        }
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

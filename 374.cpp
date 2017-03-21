// 374. Guess Number Higher or Lower - https://leetcode.com/problems/guess-number-higher-or-lower

#include <bits/stdc++.h>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long L = 1LL - 1;
        long long R = (long long)n + 1;
        int response = 0;
        while(R - L > 1) {
            long long M = L + (R - L) / 2;
            response = guess(M);
            if (response == 1) {
                L = M;
            } else if (response == -1) {
                R = M;
            } else {
                return M;
            }
        }
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

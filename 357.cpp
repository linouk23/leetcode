// 357. Count Numbers with Unique Digits - https://leetcode.com/problems/spiral-matrix

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) { return 1;  }
        n = min(10, n);
        int cur_result = 9;
        int full_result = 10;
        for (int k = 2; k <= n; ++k) {
            cur_result *= (11 - k);
            full_result += cur_result;
        }
        return full_result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 507. Perfect Number - https://leetcode.com/problems/perfect-number

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 0) return false;
        int result = 0;
        int divisor = 2;
        for (; pow(divisor, 2) < num; ++divisor) {
            if (num % divisor) { continue; }
            result += divisor;
            result += (num / divisor);
        }
        if (divisor * divisor == num) {
            result += divisor;
        }
        if (num > 1) {
            result += 1;
        }
        return result == num;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

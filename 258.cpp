// 258. Add Digits - https://leetcode.com/problems/add-digits

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num < 10) {
            return num;
        }

        int rem = num % 9;
        return (rem ? rem : rem + 9);
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.addDigits(25) == 7);
    assert(solution.addDigits(28) == 1);
    assert(solution.addDigits(16) == 7);
    assert(solution.addDigits(4) == 4);
    assert(solution.addDigits(1) == 1);

    return 0;
}

// 367. Valid Perfect Square - https://leetcode.com/problems/valid-perfect-square

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 0) {
            return false;
        }
        long long target = (long long)num;
        long long L = 0;
        long long R = (long long)num + 1;
        while (R - L > 1) {
            long long M = L + (R - L) / 2;
            if (M * M > target) {
                R = M;
            } else {
                L = M;
            }
        }

        return L * L == target;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.isPerfectSquare(0) == false);
    assert(solution.isPerfectSquare(1) == true);
    assert(solution.isPerfectSquare(14) == false);
    assert(solution.isPerfectSquare(6) == false);
    assert(solution.isPerfectSquare(64) == true);

    return 0;
}

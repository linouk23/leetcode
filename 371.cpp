// 371. Sum of Two Integers - https://leetcode.com/problems/sum-of-two-integers

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        return (b == 0) ? a : getSum(a ^ b, (a & b) << 1);
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.getSum(1, 2) == 3);
    assert(solution.getSum(1, 1) == 2);
    assert(solution.getSum(0, 0) == 0);
    assert(solution.getSum(111, 222) == 333);
    assert(solution.getSum(19, 22) == 41);
    assert(solution.getSum(999, 1) == 1000);
    assert(solution.getSum(999, 12) == 1011);

    return 0;
}

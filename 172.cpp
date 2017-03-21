// 172. Factorial Trailing Zeroes - https://leetcode.com/problems/factorial-trailing-zeroes

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int answer = 0;
        for (long long mult = 5; mult <= n; mult *= 5) {
            answer += (n / mult);
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.trailingZeroes(0) == 0);
    assert(solution.trailingZeroes(2) == 0);
    assert(solution.trailingZeroes(5) == 1);
    assert(solution.trailingZeroes(9) == 1);
    assert(solution.trailingZeroes(10) == 2);
    assert(solution.trailingZeroes(18) == 3);
    assert(solution.trailingZeroes(120) == 28);
    assert(solution.trailingZeroes(1800) == 448);
    assert(solution.trailingZeroes(1808548329) == 452137076);

    return 0;
}

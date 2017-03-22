// 70. Climbing Stairs - https://leetcode.com/problems/climbing-stairs

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 3);
        dp[1] = 1;
        dp[2] = 2;
        for (int index = 3; index <= n; ++index) {
            dp[index] = dp[index - 1] + dp[index - 2];
        }

        return dp[n];
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.climbStairs(1) == 1);
    assert(solution.climbStairs(2) == 2);
    assert(solution.climbStairs(3) == 3);

    return 0;
}

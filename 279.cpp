// 279. Perfect Squares - https://leetcode.com/problems/perfect-squares

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> dp;
public:
    int rec(int n) {
        if (n < 0) {
            return 1e9;
        }

        if (n == 0) {
            return 0;
        }

        if (dp[n]) {
            return dp[n];
        }

        int answer = 1e9;
        for (int sq_num = 1; sq_num * sq_num <= n; ++sq_num) {
            answer = min(answer, rec(n - sq_num * sq_num) + 1);
        }

        dp[n] = answer;
        return dp[n];
    }

    int numSquares(int n) {
        dp.resize(n + 1, 0);
        return rec(n);
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.numSquares(12) == 3);
    assert(solution.numSquares(13) == 2);

    return 0;
}

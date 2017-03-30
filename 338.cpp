// 338. Counting Bits - https://leetcode.com/problems/counting-bits

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        dp[0] = 0;
        for (int n = 1; n <= num; ++n) {
            dp[n] = dp[n >> 1] + (n & 1); 
        }
        return dp;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> expected_ans = {0, 1, 1, 2, 1, 2};
    assert(solution.countBits(5) == expected_ans);

    return 0;
}

// 518. Coin Change 2 - https://leetcode.com/problems/coin-change-2

#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;
// const int INF = 1e9;

class Solution {
private:
    vector<int> dp;
    vector<int> coins;
    void reset() {
        dp.clear();
        dp.resize(N, 0);
    }
public:
    int change(int amount, vector<int>& coins) {
        reset();
        dp[0] = 1;
        for (int coin : coins) {
            for (int sum = coin; sum <= amount; ++sum) {
                dp[sum] += dp[sum - coin];
            }
        }
        
        return dp[amount];
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {1, 2, 5};
    assert(solution.change(5, input) == 4);

    input = { 2 };
    assert(solution.change(3, input) == 0);

    input = { 10 };
    assert(solution.change(10, input) == 1);

    return 0;
}

// 322. Coin Change - https://leetcode.com/problems/coin-change

#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;
const int INF = 1e9;

class Solution {
private:
    vector<int> dp;
    vector<int> coins;
    void reset() {
        dp.clear();
        dp.resize(N, 0);
        coins.clear();
    }
public:
    int helper(int amount) {
        if (amount < 0) { return INF; }
        if (amount == 0) { return 0; }
        if (dp[amount]) { return dp[amount]; }

        int answer = INF;
        for (int coin : coins) {
            answer = min(answer, helper(amount - coin) + 1);
        }

        dp[amount] = answer;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        reset();
        this->coins = coins;
        int answer = helper(amount);
        return answer == INF ? -1 : answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {1, 2, 5};
    assert(solution.coinChange(input, 11) == 3);

    input = { 2 };
    assert(solution.coinChange(input, 3) == -1);

    return 0;
}

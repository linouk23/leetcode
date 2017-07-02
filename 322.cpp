// 322. Coin Change - https://leetcode.com/problems/coin-change

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<int, int> dp;
    vector<int> coins_;
    int f(int n) {
        if (n == 0) { return   0; }
        if (n <  0) { return 1e9; }
        if (dp.count(n)) { return dp[n]; }
        int result = 1e9;
        for (int coin : coins_) {
            result = min(result, f(n - coin) + 1);
        }
        dp[n] = result;
        return dp[n];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        coins_ = coins;
        int result = f(amount);
        return result == 1e9 ? -1 : result;
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

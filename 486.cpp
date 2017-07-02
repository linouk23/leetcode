// 486. Predict the Winner - https://leetcode.com/problems/predict-the-winner

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int> > dp(n, vector<int> (n, 0));
        for (int idx = 0; idx < n; ++idx) {
            dp[idx][idx] = nums[idx];
        }
        for (int idx = 0; idx + 1 < n; ++idx) {
            dp[idx][idx + 1] = max(nums[idx], nums[idx + 1]);
        }
        
        for (int diff = 2; diff < n; ++diff) {
            for (int L = 0; L + diff < n; ++L) {
                int R = L + diff;
                dp[L][R] = max(nums[L] + min(dp[L + 2][R], dp[L + 1][R - 1]),
                               nums[R] + min(dp[L + 1][R - 1], dp[L][R - 2])
                               );
            }
        }
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return (dp[0][n - 1] >= sum - dp[0][n - 1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

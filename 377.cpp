// 377. Combination Sum IV - https://leetcode.com/problems/combination-sum-iv

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target + 1, 0);
        dp[0] = 1;
        for (int sum = 0; sum <= target; ++sum) {
            for (int num : nums) {
                if (sum + num > target) { continue; }
                dp[sum + num] += dp[sum];
            }
        }
        return dp[target];
    }
private:
    vector<int> dp;
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

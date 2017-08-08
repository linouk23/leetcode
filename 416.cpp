// 416. Partition Equal Subset Sum - https://leetcode.com/problems/partition-equal-subset-sum

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> nums) {
        // Trick: nums[i] <= 200 => knapsack.
        int n = (int)nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) { return false; }
        int target = sum / 2;
        vector<deque<bool>> dp(sum / 2 + 1, deque<bool>(n + 1, false));
        // Let dp[x][k] = true if we can construct a sum x
        // using the first k weights,
        // and otherwise dp[x][k] = false.
        // Base case:
        for (int k = 0; k <= n; ++k) {
            dp[0][k] = true;
        }
        // term 99, dp[99][2] = dp[99 - 99][2 - 1] = true
        for (int idx = 0; idx < n; ++idx) {
            int term = nums[idx];
            int k = idx + 1;
            for (int sum = term; sum <= target; ++sum) {
                dp[sum][k] = dp[sum][k - 1] || dp[sum - term][k - 1];
            }
        }
        bool result = dp[target][n];
        return result;
    }
};

// bool canPartition(vector<int>& nums) {
//     bitset<5001> bits(1);
//     int sum = accumulate(nums.begin(), nums.end(), 0);
//     for (auto n : nums) bits |= bits << n;
//     return !(sum & 1) && bits[sum >> 1];
// }

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

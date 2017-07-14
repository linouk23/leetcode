// 487. Max Consecutive Ones II - https://leetcode.com/problems/max-consecutive-ones-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> nums) {
        if (nums.empty()) { return 0; }
        int n = (int)nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        if (nums[0] == 1) {
            dp[0][0] = 1;
        } else {
            dp[0][1] = 1;
        }
        for (int idx = 1; idx < n; ++idx) {
            if (nums[idx] == 1) {
                dp[idx][0] = dp[idx - 1][0] + 1;
                dp[idx][1] = dp[idx - 1][1] + 1;
            } else {
                dp[idx][0] = 0;
                dp[idx][1] = dp[idx - 1][0] + 1;
            }
        }
        int result = 0;
        for (int idx = 0; idx < n; ++idx) {
            result = max({result,
                          dp[idx][0],
                          dp[idx][1],
            });
        }
        return result;
    }
};

// https://discuss.leetcode.com/topic/75445/java-clean-solution-easily-extensible-to-flipping-k-zero-and-follow-up-handled/4
//public int findMaxConsecutiveOnes(int[] nums) {
//    int max = 0, zero = 0, k = 1; // flip at most k zero
//    for (int l = 0, h = 0; h < nums.length; h++) {
//        if (nums[h] == 0)
//            zero++;
//        while (zero > k)
//            if (nums[l++] == 0)
//                zero--;
//        max = Math.max(max, h - l + 1);
//    }
//    return max;
//}

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 376. Wiggle Subsequence - https://leetcode.com/problems/wiggle-subsequence

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) { return 0; }
        int n = (int)nums.size();
        const int LOCAL_MAX = 1;
        const int LOCAL_MIN = 0;
        // Let dp[i][j] be the max length of the WS
        // for the first i elements so far.
        // j is the flag | 0 -> local min
        //               | 1 -> local max
        // Any WS can be written as either 1010... or 0101...
        vector<vector<int> > dp(n, vector<int> (2, 0));
        // A sequence with fewer than two elements is
        // trivially a wiggle sequence.
        dp[0][LOCAL_MIN] = 1;
        dp[0][LOCAL_MAX] = 1;
        for (int len = 1; len < n; ++len) {
            if (nums[len] > nums[len - 1]) {
                // e.g., 4 16 -> 16 > 4 (LOCAL_MAX improves)
                // dp[len][LOCAL_MAX] = dp[len - 1][LOCAL_MAX]
                dp[len][LOCAL_MAX] = max(dp[len - 1][LOCAL_MAX],
                                         dp[len - 1][LOCAL_MIN] + 1
                );
                dp[len][LOCAL_MIN] = dp[len - 1][LOCAL_MIN];
            } else if (nums[len] < nums[len - 1]) {
                // e.g., 16 4 -> 4 < 16 (LOCAL_MIN improves)
                // dp[len][LOCAL_MIN] = dp[len - 1][LOCAL_MAX]
                dp[len][LOCAL_MIN] = max(dp[len - 1][LOCAL_MIN],
                                         dp[len - 1][LOCAL_MAX] + 1
                                         );
                dp[len][LOCAL_MAX] = dp[len - 1][LOCAL_MAX];
            } else { // (nums[len] == nums[len - 1])
                dp[len][LOCAL_MIN] = dp[len - 1][LOCAL_MIN];
                dp[len][LOCAL_MAX] = dp[len - 1][LOCAL_MAX];
            }
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

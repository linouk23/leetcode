// 413. Arithmetic Slices - https://leetcode.com/problems/arithmetic-slices

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    vector<int> nums;
    bool isDiffOK(int index) {
        return nums[index] - nums[index - 1] ==
               nums[index - 1] - nums[index - 2];
    }
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        nums = A;
        int n = (int)nums.size();
        if (n < 3) { return 0; }
        // Let dp[i] be the number of the AS which is ending at element with index i.
        vector<int> dp(n + 3, 0);
        if (isDiffOK(2)) {
            dp[2] = 1;
        }
        for (int idx = 3; idx < n; ++idx) {
            if (isDiffOK(idx)) {
                // Append A[i] to each AS (increasing length)
                dp[idx] += dp[idx - 1];
                
                // New triplet is found
                dp[idx] += 1;
            }
        }
        int result = accumulate(dp.begin(), dp.end(), 0);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

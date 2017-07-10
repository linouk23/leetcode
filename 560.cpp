// 560. Subarray Sum Equals K - https://leetcode.com/problems/subarray-sum-equals-k

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        // sum -> count
        unordered_map<int, int> prefix;
        int n = (int)nums.size();
        int sum = 0;
        prefix[sum] = 1;
        int result = 0;
        for (int idx = 0; idx < n; ++idx) {
            int num = nums[idx];
            sum += num;
            if (prefix.count(sum - k)) {
                result += prefix[sum - k];
            }
            prefix[sum] += 1;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

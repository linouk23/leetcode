// 325. Maximum Size Subarray Sum Equals k Two Sum - https://leetcode.com/problems/maximum-size-subarray-sum-equals-k

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum;
        // key is the sum, value is min_index (0..min_index)
        int n = (int)nums.size();
        int result = 0;
        int sum_so_far = 0;
        prefix_sum[0] = -1;
        for (int index = 0; index < n; ++index) {
            int number = nums[index];
            sum_so_far += number;
            if (prefix_sum.count(sum_so_far)) {
                prefix_sum[sum_so_far] = index;
            }
            if (prefix_sum.count(sum_so_far - k)) {
                int cur_distance = index - prefix_sum[sum_so_far - k];
                result = max(result, cur_distance);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

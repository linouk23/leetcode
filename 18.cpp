// 18. 4Sum - https://leetcode.com/problems/4sum

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        vector<vector<int> > result;
        for (int idx1 = 0; idx1 < n; ++idx1) {
            int sum3_to_find = -nums[idx1] + target;
            for (int idx2 = idx1 + 1; idx2 < n; ++idx2) {
                int sum2_to_find = sum3_to_find - nums[idx2];
                int L = idx2 + 1;
                int R = n - 1;
                while (L < R) {
                    int cur_sum = nums[L] + nums[R];
                    if (cur_sum > sum2_to_find) {
                        --R;
                    } else if (cur_sum < sum2_to_find) {
                        ++L;
                    } else {
                        result.push_back({nums[idx1], nums[idx2], nums[L], nums[R]});
                        while (L < R && nums[L] == result.back()[2]) {
                            ++L;
                        }
                        while (L < R && nums[R] == result.back()[3]) {
                            --R;
                        }
                    }
                }
                while (idx2 + 1 < n && nums[idx2] == nums[idx2 + 1]) { ++idx2; }
            }
            while (idx1 + 1 < n && nums[idx1] == nums[idx1 + 1]) { ++idx1; }
        }
        return result;
    }
};


int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

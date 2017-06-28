// 15. 3Sum - https://leetcode.com/problems/3sum

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    static vector<vector<int>> threeSum(vector<int> nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for (int idx = 0; idx < (int)nums.size(); ++idx) {
            if (idx > 0 && nums[idx] == nums[idx - 1]) { continue; }
            int sum_to_find = -1 * nums[idx];
            int L = idx + 1;
            int R = (int)nums.size() - 1;
            while (L < R) {
                int cur_sum = nums[L] + nums[R];
                if (cur_sum > sum_to_find) {
                    --R;
                } else if (cur_sum == sum_to_find) {
                    result.push_back({-1 * sum_to_find, nums[L++], nums[R--]});
                    while (L < R && nums[L] == nums[L - 1]) {
                        ++L;
                    }
                    while (L < R && nums[R] == nums[R + 1]) {
                        --R;
                    }
                } else {
                    ++L;
                }
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

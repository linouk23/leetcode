// 410. Split Array Largest Sum - https://leetcode.com/problems/split-array-largest-sum

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool check(int largest_sum, int m, vector<int>& nums) {
        int num_of_completed_groups = 0, cur_sum = 0;
        for (int num : nums) {
            if (num > largest_sum) {
                return false;
            }
            if (cur_sum + num > largest_sum) {
                ++num_of_completed_groups;
                cur_sum = num;
            } else {
                cur_sum += num;
            }
        }
        if (cur_sum) {
            ++num_of_completed_groups;
        }
        return num_of_completed_groups <= m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int L = *max_element(nums.begin(), nums.end()) - 1;
        int R = accumulate(nums.begin(), nums.end(), 0);
        while (R - L > 1) {
            int largest_sum = L + (R - L) / 2;
            if (check(largest_sum, m, nums)) {
                R = largest_sum;
            } else {
                L = largest_sum;
            }
        }
        return R;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

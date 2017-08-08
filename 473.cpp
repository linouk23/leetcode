// 473. Matchsticks to Square - https://leetcode.com/problems/matchsticks-to-square

#include "bits/stdc++.h"

using namespace std;

// Partition problem is the task
// of deciding whether a given multiset S of positive integers
// can be partitioned into 4 subsets S1, ..., S4 such that the
// sum of S1 = sum of S2 = sum of S3 = sum of S4.

class Solution {
private:
    int n;
    int NUM_OF_SUMS = 4;
    bool call_next(int sum_idx, vector<int>& nums, deque<bool> &used, vector<int> &sums, int target) {
        if (sums[sum_idx] == target) {
            return dfs(sum_idx + 1, nums, used, sums, target);
        } else {
            return dfs(sum_idx, nums, used, sums, target);
        }
    }
    
    bool dfs(int sum_idx, vector<int>& nums, deque<bool> used, vector<int> sums, int target) {
        if (sum_idx == NUM_OF_SUMS) {
            return true;
        }
        for (int idx = 0; idx < n; ++idx) {
            if (used[idx]) { continue; }
            int num = nums[idx];
            if (sums[sum_idx] + num > target) { continue; }
            
            used[idx] = true;
            sums[sum_idx] += num;
            if (call_next(sum_idx, nums, used, sums, target)) {
                return true;
            }
            
            used[idx] = false;
            sums[sum_idx] -= num;
        }
        return false;
    }
public:
    bool makesquare(vector<int> nums) {
        if (nums.empty()) { return false; }
        n = (int)nums.size();
        deque<bool> used(n, false);
        vector<int> sums(4, 0);
        // Trick.
        sort(nums.rbegin(), nums.rend());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4) { return false; }
        int target = sum / 4;
        if (nums[0] > target ||
           ((nums[0] < target) && (nums[0] + nums[n - 1] > target))) {
            return false;
        }
        bool result = dfs(0, nums, used, sums, target);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

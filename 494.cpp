// 494. Target Sum - https://leetcode.com/problems/target-sum

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int result = 0, n;
    vector<int> nums_;
    void helper(int index, int sum, int target) {
        if (index == n) {
            if (sum == target) { ++result; }
            return;
        }
        helper(index + 1, sum + nums_[index], target);
        helper(index + 1, sum - nums_[index], target);
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        nums_ = nums;
        n = (int)nums_.size();
        helper(0, 0, S);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

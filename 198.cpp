// 198. House Robber - https://leetcode.com/problems/house-robber

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp((int)nums.size());
        if (nums.empty()) {
            return 0;
        }

        if ((int)nums.size() == 1) {
            return nums[0];
        }

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int house = 2; house < (int)nums.size(); ++house) {
            dp[house] = max(dp[house - 1], dp[house - 2] + nums[house]);
        }

        return dp[(int)nums.size() - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {1, 2, 31, 1, 2, 2, 2, 3};
    assert(solution.rob(input) == 37);

    input = {};
    assert(solution.rob(input) == 0);

    input = {122, 2, 31, 1, 22, 2, 2, 3};
    assert(solution.rob(input) == 178);

    input = {2, 2, 2, 2, 2, 2};
    assert(solution.rob(input) == 6);

    return 0;
}

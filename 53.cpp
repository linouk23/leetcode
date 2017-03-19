// 53. Maximum Subarray - https://leetcode.com/problems/maximum-subarray

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // The idea is to calculate, for each array position, the
        // maximum sum of a subarray that ends at that position.
        vector<int> dp((int)nums.size());
        dp[0] = nums[0];

        // There are two possibilities:
        // 1. The subarray only contains the element at position index.
        // 2. The subarray consists of a subarray that ends at position index − 1,
        // followed by the element at position index.
        for (int index = 1; index < (int)nums.size(); ++index) {
            dp[index] = max(0, dp[index - 1]) + nums[index];
        }

        int answer = INT_MIN;
        for (const int &sum : dp) {
            answer = max(answer, sum);
        }

        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(solution.maxSubArray(input) == 6);

    input = {-100};
    assert(solution.maxSubArray(input) == -100);

    input = {-2, -1, 3, -3, -4, 5};
    assert(solution.maxSubArray(input) == 5);

    return 0;
}

// 167. Two Sum II - Input array is sorted - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = (int)numbers.size() - 1;

        while(left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                break;
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }

        return {left + 1, right + 1};
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {2, 7, 11, 15};
    vector<int> expected_ans = {1, 2};
    assert(solution.twoSum(input, 9) == expected_ans);

    return 0;
}

// 1. Two Sum - https://leetcode.com/problems/two-sum

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        int left = 0, right = 0;

        for (int index = 0; index < (int)nums.size(); ++index) {
            int complement = target - nums[index];

            if (hashtable.count(complement)) {
                left = hashtable[complement];
                right = index;
                break;
            }

            hashtable[nums[index]] = index;
        }

        return {left, right};
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {2, 7, 11, 15};
    vector<int> expected_ans = {0, 1};
    assert(solution.twoSum(input, 9) == expected_ans);

    input = {12, 7, 111, 15};
    expected_ans = {1, 3};
    assert(solution.twoSum(input, 22) == expected_ans);

    return 0;
}

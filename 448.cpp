// 448. Find All Numbers Disappeared in an Array - https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int index = 0; index < (int)nums.size(); ++index) {
            int num_index = abs(nums[index]) - 1;
            if (nums[num_index] > 0) {
                nums[num_index] *= -1;
            }
        }
        vector<int> answer;
        for (int index = 0; index < (int)nums.size(); ++index) {
            if (nums[index] > 0) {
                answer.emplace_back(index + 1);
            }
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> expected_ans = {5, 6};
    assert(solution.findDisappearedNumbers(input) == expected_ans);

    input = {};
    expected_ans = {};
    assert(solution.findDisappearedNumbers(input) == expected_ans);
    
    input = {2, 2};
    expected_ans = {1};
    assert(solution.findDisappearedNumbers(input) == expected_ans);

    return 0;
}

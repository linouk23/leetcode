// 283. Move Zeroes - https://leetcode.com/problems/move-zeroes

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
        int index_to_write = 0;
        for (int index = 0; index < (int)nums.size(); ++index) {
            if (nums[index]) {
                nums[index_to_write++] = nums[index];
            }
        }

        for (int index = index_to_write; index < (int)nums.size(); ++index) {
            nums[index] = 0;
        }

        return nums;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {0, 1, 0, 3, 12};
    vector<int> expected_ans = {1, 3, 12, 0, 0};
    assert(solution.moveZeroes(input) == expected_ans);

    input = {0};
    expected_ans = {0};
    assert(solution.moveZeroes(input) == expected_ans);

    input = {0, 0, 0, 0, 0};
    expected_ans = {0, 0, 0, 0, 0};
    assert(solution.moveZeroes(input) == expected_ans);

    input = {1, 1, 1, 1};
    expected_ans = {1, 1, 1, 1};
    assert(solution.moveZeroes(input) == expected_ans);

    return 0;
}

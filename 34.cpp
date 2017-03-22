// 34. Search for a Range - https://leetcode.com/problems/search-for-a-range

#include <bits/stdc++.h>

using namespace std;

bool greater_than(int a, int b) {
    return (a > b);
}

bool greater_than_or_equal_to(int a, int b) {
    return (a >= b);
}

class Solution {
private:
    vector<int> nums;
    int target;
public:
    int binary_search(bool should_return_left, bool (*functocall)(int, int)) {
        int L = 0 - 1;
        int R = (int)nums.size();
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if ((*functocall)(nums[M], target)) {
                R = M;
            } else {
                L = M;
            }
        }

        if (should_return_left) {
            L = (L < (int)nums.size() && nums[L] == target) ? L : -1;
        } else {
            R = (R >= 0 && nums[R] == target) ? R : -1;
        }

        return (should_return_left ? L : R);
    }

    int get_right_border() {
        return binary_search(true, greater_than);
    }

    int get_left_border() {
        return binary_search(false, greater_than_or_equal_to);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        int left_border = get_left_border();
        int right_border = get_right_border();
        return {left_border, right_border};
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {5, 7, 7, 8, 8, 10};
    vector<int> expected_ans = {3, 4};
    assert(solution.searchRange(input, 8) == expected_ans);

    input = {5, 7, 7, 8, 8, 10};
    expected_ans = {-1, -1};
    assert(solution.searchRange(input, 9) == expected_ans);

    input = {5, 7, 7, 8, 8, 10};
    expected_ans = {0, 0};
    assert(solution.searchRange(input, 5) == expected_ans);

    input = {5, 7, 7, 8, 8, 10};
    expected_ans = {5, 5};
    assert(solution.searchRange(input, 10) == expected_ans);

    input = {};
    expected_ans = {-1, -1};
    assert(solution.searchRange(input, 10) == expected_ans);

    input = {-1};
    expected_ans = {-1, -1};
    assert(solution.searchRange(input, 0) == expected_ans);

    input = {-99999};
    expected_ans = {-1, -1};
    assert(solution.searchRange(input, 0) == expected_ans);

    return 0;
}

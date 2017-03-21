// 189. Rotate Array - https://leetcode.com/problems/rotate-array

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k = k % n;
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.rbegin(), nums.rend());
        return nums;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {1, 2, 3, 4, 5, 6, 7};
    vector<int> expected_ans = {5, 6, 7, 1, 2, 3, 4};
    assert(solution.rotate(input, 3) == expected_ans);

    input = {-1};
    expected_ans = {-1};
    assert(solution.rotate(input, 2) == expected_ans);

    return 0;
}

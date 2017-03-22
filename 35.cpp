// 35. Search Insert Position - https://leetcode.com/problems/search-insert-position

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L = 0 - 1;
        int R = (int)nums.size();

        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (nums[M] > target) {
                R = M;
            } else if (nums[M] < target) {
                L = M;
            } else {
                return M;
            }
        }

        return R;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {1, 3, 5, 6};
    assert(solution.searchInsert(input, 5) == 2);
    assert(solution.searchInsert(input, 2) == 1);
    assert(solution.searchInsert(input, 7) == 4);
    assert(solution.searchInsert(input, 0) == 0);

    return 0;
}

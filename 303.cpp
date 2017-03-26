// 303. Range Sum Query - Immutable - https://leetcode.com/problems/range-sum-query-immutable

#include <bits/stdc++.h>

using namespace std;

class NumArray {
private:
    vector<int> prefix_sums;
public:
    NumArray(vector<int> nums) {
        if (nums.empty()) {
            return;
        }
        prefix_sums.resize(nums.size() + 1);
        prefix_sums[0] = 0;
        for (int index = 1; index < (int)nums.size() + 1; ++index) {
            prefix_sums[index] = prefix_sums[index - 1] + nums[index - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return prefix_sums[j + 1] - prefix_sums[i];
    }
};

int main() {
    ios::sync_with_stdio(false);

    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray solution(nums);

    assert(solution.sumRange(0, 2) == 1);
    assert(solution.sumRange(2, 5) == -1);
    assert(solution.sumRange(0, 5) == -3);

    return 0;
}

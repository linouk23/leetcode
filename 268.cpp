// 268. Missing Number - https://leetcode.com/problems/missing-number

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long actual_sum = 0;
        for (const int &num : nums) {
            actual_sum += num;
        }

        int n = (int)nums.size();
        long long sum = 1LL * n * (n + 1) / 2;
        return int(sum - actual_sum);
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {1, 0, 2, 3, 4, 6, 7, 8};
    assert(solution.missingNumber(input) == 5);

    input = {1, 2, 3, 4};
    assert(solution.missingNumber(input) == 0);

    input = {0, 1, 3};
    assert(solution.missingNumber(input) == 2);

    input = {0};
    assert(solution.missingNumber(input) == 1);

    return 0;
}

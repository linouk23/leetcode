// 485. Max Consecutive Ones - https://leetcode.com/problems/max-consecutive-ones

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int best_ans = 0, cur_ans = 0;
        for (const int &num : nums) {
            if (num == 0) {
                best_ans = max(best_ans, cur_ans);
                cur_ans = 0;
            } else {
                ++cur_ans;
            }
        }
        best_ans = max(best_ans, cur_ans);

        return best_ans;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {1, 1, 0, 1, 1, 1};
    assert(solution.findMaxConsecutiveOnes(input) == 3);

    input = {1, 1, 0};
    assert(solution.findMaxConsecutiveOnes(input) == 2);

    input = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    assert(solution.findMaxConsecutiveOnes(input) == 0);

    input = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    assert(solution.findMaxConsecutiveOnes(input) == 9);

    input = {};
    assert(solution.findMaxConsecutiveOnes(input) == 0);

    return 0;
}

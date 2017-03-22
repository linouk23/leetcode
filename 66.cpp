// 66. Plus One - https://leetcode.com/problems/plus-one

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 1;
        for (int index = (int)digits.size() - 1; index >= 0; --index) {
            int sum = carry + digits[index];
            result.emplace_back(sum % 10);
            carry = sum / 10;
        }
        if (carry) {
            result.emplace_back(carry);
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {0};
    vector<int> expected_ans = {1};
    assert(solution.plusOne(input) == expected_ans);

    input = {9, 9, 9};
    expected_ans = {1, 0, 0, 0};
    assert(solution.plusOne(input) == expected_ans);

    return 0;
}

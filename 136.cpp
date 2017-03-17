// 136. Single Number - https://leetcode.com/problems/single-number

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int missing_number = 0;
        for (const int &num : nums) {
            missing_number ^= num;
        }

        return missing_number;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {1, 2, 3, 4, 1, 2, 3};
    assert(solution.singleNumber(input) == 4);

    input = {1, 1, 2};
    assert(solution.singleNumber(input) == 2);

    input = {100};
    assert(solution.singleNumber(input) == 100);

    return 0;
}

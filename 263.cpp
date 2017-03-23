// 263. Ugly Number - https://leetcode.com/problems/ugly-number

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }

        vector<int> nums = {2, 3, 5};
        for (int n : nums) {
            while (num % n == 0) {
                num /= n;
            }
        }

        return num == 1;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.isUgly(1) == true);
    assert(solution.isUgly(14) == false);
    assert(solution.isUgly(6) == true);
    assert(solution.isUgly(8) == true);

    return 0;
}

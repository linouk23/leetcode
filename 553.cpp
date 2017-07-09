// 553. Optimal Division - https://leetcode.com/problems/optimal-division

#include "bits/stdc++.h"

using namespace std;

// X1/X2/X3/../Xn will always be equal to (X1/X2) * Y,
// no matter how you place parentheses. i.e no matter how
// you place parentheses, X1 always goes to the numerator
// and X2 always goes to the denominator. Hence you just need
// to maximize Y. And Y is maximized when it is equal to
// X3 * ...* Xn => (X1 * X3 * ... * Xn) / X2 = X1 / (X2/X3/../Xn)

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string result;
        if(nums.empty()) return result;
        result = to_string(nums[0]);
        int n = (int)nums.size();
        if (n == 1) { return result; }
        if (n == 2) { return result + "/" + to_string(nums[1]); }
        result += "/(" + to_string(nums[1]);
        for (int idx = 2; idx < n; ++idx)
            result += "/" + to_string(nums[idx]);
        result += ")";
        return result;
    }
};



int main() {
    ios::sync_with_stdio(false);
    return 0;
}

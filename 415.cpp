// 415. Add Strings - https://leetcode.com/problems/add-strings

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = (int)num1.size() - 1;
        int j = (int)num2.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0) + carry;
            result += to_string(sum % 10);
            carry = sum / 10;
            --i;
            --j;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;
    
    assert(solution.addStrings("0", "0") == "0");
    assert(solution.addStrings("1", "9") == "10");
    assert(solution.addStrings("111", "222") == "333");

    return 0;
}

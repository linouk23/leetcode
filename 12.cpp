// 12. Integer to Roman - https://leetcode.com/problems/integer-to-roman

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> M = {"", "M", "MM", "MMM"};
        vector<string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.intToRoman(621) == "DCXXI");
    assert(solution.intToRoman(21) == "XXI");
    assert(solution.intToRoman(9) == "IX");
    assert(solution.intToRoman(3) == "III");

    return 0;
}

// 405. Convert a Number to Hexadecimal - https://leetcode.com/problems/convert-a-number-to-hexadecimal

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        vector<char> alphabet = {
            '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'
        };

        if (num == 0) {
            return "0";
        }

        string result = "";
        while(num != 0 && result.size() < 8) {
            int carry = num % 16;
            // Or use num & 15.
            if (carry < 0) {
                carry += 16;
            }
            result = alphabet[carry] + result;
            num >>= 4;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.toHex(26) == "1a");
    assert(solution.toHex(-1) == "ffffffff");

    return 0;
}

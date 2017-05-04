// 91. Decode Ways - https://leetcode.com/problems/decode-ways

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        auto is_valid_num = [](char prev, char cur) -> bool {
           if (prev == '0') { return false; }
           int number = 10 * (prev - '0') + (cur - '0');
           return number <= 26;
        };
        auto is_not_zero = [](char cur) -> bool {
            return cur != '0';
        };
        
        if (s.empty()) { return 0; }
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        dp[1] = (is_not_zero(s[0])) ? 1 : 0;
        for (int index = 2; index <= s.length(); ++index) {
            if (is_not_zero(s[index - 1])) {
                dp[index] += dp[index - 1];
            }
            if (is_valid_num(s[index - 2], s[index - 1])) {
                dp[index] += dp[index - 2];
            }
        }
        return dp[s.length()];
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

// 91. Decode Ways - https://leetcode.com/problems/decode-ways

#include "bits/stdc++.h"

using namespace std;

// class Solution {
// public:
//     int numDecodings(string s) {
//         auto is_valid_num = [](char prev, char cur) -> bool {
//            if (prev == '0') { return false; }
//            int number = 10 * (prev - '0') + (cur - '0');
//            return number <= 26;
//         };
//         auto is_not_zero = [](char cur) -> bool {
//             return cur != '0';
//         };
        
//         if (s.empty()) { return 0; }
//         vector<int> dp(s.length() + 1, 0);
//         dp[0] = 1;
//         dp[1] = (is_not_zero(s[0])) ? 1 : 0;
//         for (int index = 2; index <= s.length(); ++index) {
//             if (is_not_zero(s[index - 1])) {
//                 dp[index] += dp[index - 1];
//             }
//             if (is_valid_num(s[index - 2], s[index - 1])) {
//                 dp[index] += dp[index - 2];
//             }
//         }
//         return dp[s.length()];
//     }
// };

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) { return 0; }
        int n = (int)s.length();
        vector<int> dp(n + 1);
        // Base case.
        dp[0] = 1;
        dp[1] = (s[0] != '0') ? 1 : 0;
        for(int idx = 2; idx <= n; ++idx) {
            int first = stoi(s.substr(idx - 1, 1));
            int second = stoi(s.substr(idx - 2, 2));
            // Adding one separate digit from 1 to 9 (A to I).
            // |{AB, L}| = |{1th+2nd, 12th}| = 2 ->
            // Push back 3rd letter ('C') => |{1th+2nd+3rd, 12th + 3rd}| = 
            // = |{ABC, LC}| = 2
            if (first >= 1 && first <= 9) {
                dp[idx] += dp[idx - 1];
            }
            // Adding two digits from 10 to 26 (J to Z).
            // |{A}| = |{1th}| = 1 ->
            // Push back 23rd letter ('W') => |{1th+23rd}| = 
            // = |{AW}| = 1
            if (second >= 10 && second <= 26) {
                dp[idx] += dp[idx - 2];
            }
        }
        return dp[n];
    }
};


int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

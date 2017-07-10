// 639. Decode Ways II - https://leetcode.com/problems/decode-ways-ii

#include "bits/stdc++.h"

using namespace std;

//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26

//Input: "*"
//Output: 9
//Input: "1*"
//Output: 9 + 9 = 18
typedef long long ll;

class Solution {
private:
    long long mod = 1e9 + 7;
    void add(ll &a, ll b) {
        a = (a % mod + b % mod) % mod;
    }
    ll mult(ll a, ll b) {
        return (a % mod * b % mod) % mod;
    }
public:
    int numDecodings(string s) {
        if (s.empty()) { return 0; }
        int n = (int)s.length();
        // Now the encoded string can also contain the character '*',
        // which can be treated as one of the numbers from 1 to 9.
        char star = '*';
        vector<ll> dp(n + 1, 0);
        // Base case.
        dp[0] = 1;
        if (s[0] == '0') {
            dp[1] = 0;
        } else if (s[0] == star) {
            dp[1] = 9;
        } else {
            dp[1] = 1;
        }
        
        for(int idx = 2; idx <= n; ++idx) {
            if (s[idx - 1] == star || s[idx - 2] == star) {
                // **: 00 || 09 || 90
                if (s[idx - 1] == star && s[idx - 2] == star) {
                    // The star symbol is any of '1'...'9' => 9 * x.
                    // dp[idx] += 9 * dp[idx - 1];
                    add(dp[idx], mult(9, dp[idx - 1]));
                    
                    // ** = '11'...,'19',...,'21',...,'26' = 15
                    // dp[idx] += 15 * dp[idx - 2];
                    add(dp[idx], mult(15, dp[idx - 2]));
                // 2* || 0*
                } else if (s[idx - 1] == star) {
                    // The star symbol is any of '1'...'9' => 9 * x.
                    // dp[idx] += 9 * dp[idx - 1];
                    add(dp[idx], mult(9, dp[idx - 1]));
                    
                    ll count = 0;
                    switch (s[idx - 2]) {
                        case '1':
                            // '1'...'9' => 11 = K, 12 = L, etc. = 9
                            count = 9;
                            break;
                        case '2':
                            // '1'...'6' => 6, 21 = 'U', 26 = 'Z'
                            count = 6;
                        default:
                            break;
                    }
                    // dp[idx] += count * dp[idx - 2];
                    add(dp[idx], mult(count, dp[idx - 2]));
                // *2 || *0
                } else { // s[idx - 2] == star, as usual:
                    int first = stoi(s.substr(idx - 1, 1));
                    if (first >= 1 && first <= 9) {
                        // dp[idx] += dp[idx - 1];
                        add(dp[idx], dp[idx - 1]);
                    }
                    int second = stoi("1" + s.substr(idx - 1, 1));
                    if (second >= 10 && second <= 26) {
                        // dp[idx] += dp[idx - 2];
                        add(dp[idx], dp[idx - 2]);
                    }
                    second = stoi("2" + s.substr(idx - 1, 1));
                    if (second >= 10 && second <= 26) {
                        // dp[idx] += dp[idx - 2];
                        add(dp[idx], dp[idx - 2]);
                    }
                }
            } else {
                int first = stoi(s.substr(idx - 1, 1));
                int second = stoi(s.substr(idx - 2, 2));
                // Adding one separate digit from 1 to 9 (A to I).
                // |{AB, L}| = |{1th+2nd, 12th}| = 2 ->
                // Push back 3rd letter ('C') => |{1th+2nd+3rd, 12th + 3rd}| =
                // = |{ABC, LC}| = 2
                if (first >= 1 && first <= 9) {
                    // dp[idx] += dp[idx - 1];
                    add(dp[idx], dp[idx - 1]);
                }
                // Adding two digits from 10 to 26 (J to Z).
                // |{A}| = |{1th}| = 1 ->
                // Push back 23rd letter ('W') => |{1th+23rd}| =
                // = |{AW}| = 1
                if (second >= 10 && second <= 26) {
                    // dp[idx] += dp[idx - 2];
                    add(dp[idx], dp[idx - 2]);
                }
            }
        }
        return (int)dp[n];
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

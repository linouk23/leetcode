// 76. Minimum Window Substring - https://leetcode.com/problems/minimum-window-substring

#include "bits/stdc++.h"

using namespace std;

struct Result {
    int start, finish, min_len;
};

// Trick.
class Solution {
public:
    string minWindow(string s, string t) {
        int n = (int)s.length();
        int m = (int)t.length();
        int count = m;
        Result result {0, 0, INT_MAX};
        unordered_map<char, int> tablecount;
        for (char ch : t) {
            tablecount[ch] += 1;
        }
        int L, R;
        L = R = 0;
        while (R < n) {
            while (count != 0 && R < n) {
                // R++ -> instead of count[ch]++ -> count[ch]--
                if (tablecount[s[R++]]-- > 0) {
                    --count;
                }
            }
            bool isOK = (count == 0);
            if (!isOK) { break; }
            // [L, R)

            while (count == 0) {
                // L++ -> instead of count[ch]-- -> count[ch]++
                if (tablecount[s[L++]]++ >= 0) {
                    ++count;
                }
            }
            // [L - 1, R - 1]
            if (R - L + 1 < result.min_len) {
                result.start = L - 1;
                result.finish = R - 1;
                result.min_len = R - L + 1;
            }
        }
        return result.min_len == INT_MAX ? "" : s.substr(result.start, result.min_len);
    }
};

int main() {
    ios::sync_with_stdio(false);
    Solution sol;
    sol.minWindow("ADOBECODEBANC", "ABC");
//    sol.maxSlidingWindow({1,-1}, 1);
    return 0;
}

// 28. Implement strStr() - https://leetcode.com/problems/implement-strstr

#include "bits/stdc++.h"

using namespace std;

// https://cses.fi/book.pdf
// To efficiently calculate the Z-array values,
// the algorithm maintains a range [L, R] such that
// s[L...R] is a prefix of s and R is as large as possible.
// Since we know that s[0...R - L] and s[L...R] are equal, we can use this
// information when calculating Z-values for positions L+1, L+2,..., R.

// At each position k, we first check the value of z[k − L].
// If k + z[k − L] < R, we know that z[k] = z[k − L].
// However, if k + z[k − L] ≥ y, s[0...R-k] equals s[k...R],
// and to determine the value of z[k] we need to compare the substrings
// character by character. Still, the algorithm works in O(n) time,
// because we start comparing at positions R − k +1 and R + 1.

class Solution {
private:
    vector<int> z(const string &s) {
        int n = (int)s.length();
        vector<int> z(n);
        int L = 0, R = 0;
        for (int idx = 1; idx < n; ++idx) {
            z[idx] = max(0, min(z[idx - L], R - idx + 1));
            while (idx + z[idx] < n && s[z[idx]] == s[idx + z[idx]]) {
                L = idx; R = idx + z[idx]; z[idx]++;
            }
        }
        return z;
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) { return 0; }
        char delim = '#';
        string s = needle + '#' + haystack;
        auto prefix_vec = z(s);
        int n = (int)needle.length();
        for (int idx = n + 1; idx < (int)s.length(); ++idx) {
            if (prefix_vec[idx] == n) {
                return idx - n - 1;
            }
        }
        return -1;
    }
};



int main() {
    ios::sync_with_stdio(false);
    Solution sol;
   // sol.maxEnvelopes({{30,50},{12,2},{3,4},{12,15}});
//    sol.minWindow("ADOBECODEBANC", "ABC");
//    sol.maxSlidingWindow({1,-1}, 1);
    return 0;
}

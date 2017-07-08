// 482. License Key Formatting - https://leetcode.com/problems/license-key-formatting

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int K) {
        char delim = '-';
        int idx_to_write = 0;
        for (int idx = 0; idx < (int)s.length(); ++idx) {
            if (s[idx] != delim) {
                s[idx_to_write++] = s[idx];
            }
        }
        if (idx_to_write == 0) { return ""; }
        s.erase(s.begin() + idx_to_write, s.end());
        int len = (int)s.length();
        int count = ceil((double)len / (double)K) - 1;
        int last_letter = (int)s.length() - 1;
        string empty(count, ' ');
        s += empty;
        int k = 0;
        for (int idx = (int)s.length() - 1; idx >= 0; --idx) {
            ++k;
            if (k == K + 1) {
                s[idx] = delim;
                k = 0;
            } else {
                if (isalpha(s[last_letter])) {
                    s[idx] = toupper(s[last_letter--]);
                } else {
                    s[idx] = s[last_letter--];
                }
            }
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

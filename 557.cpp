// 557. Reverse Words in a String III - https://leetcode.com/problems/reverse-words-in-a-string-iii

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        for (int L = 0; L < s.length(); ++L) {
            if (s[L] == ' ') { continue; }
            int R = L;
            while (R < s.length() && s[R] != ' ') { ++R; }
            reverse(s.begin() + L, s.begin() + R);
            L = R;
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

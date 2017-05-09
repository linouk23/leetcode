// 151. Reverse Words in a String - https://leetcode.com/problems/reverse-words-in-a-string

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int index_to_write = 0;
        for (int L = 0; L < s.size(); ++L) {
            if (s[L] != ' ') {
                if (index_to_write != 0) s[index_to_write++] = ' ';
                int R = L;
                while (R < s.size() && s[R] != ' ') { s[index_to_write++] = s[R++]; }
                reverse(s.begin() + index_to_write - (R - L), s.begin() + index_to_write);
                L = R;
            }
        }
        s.erase(s.begin() + index_to_write, s.end());
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 345. Reverse Vowels of a String - https://leetcode.com/problems/reverse-vowels-of-a-string

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int L = 0, R = (int)s.length() - 1;
        while(L < R) {
            if (!vowels.count(tolower(s[L]))) {
                ++L;
            } else if (!vowels.count(tolower(s[R]))) {
                --R;
            } else {
                swap(s[L++], s[R--]);
            }
        }
        return s;
    }
private:
    set<char> vowels = {
        'a', 'e', 'u', 'i', 'o'
    };
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 680. Valid Palindrome II - https://leetcode.com/problems/valid-palindrome-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    bool helper(const string &s, int L, int R) {
        while (L < R) {
            if (s[L++] != s[R--]) {
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int L = 0, R = s.length() - 1;
        
        while (L < R) {
            if (s[L] != s[R]) {
                return helper(s, L + 1, R) || helper(s, L, R - 1);
            }
            ++L;
            --R;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

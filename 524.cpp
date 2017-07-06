// 524. Longest Word in Dictionary through Deleting - https://leetcode.com/problems/longest-word-in-dictionary-through-deleting

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    bool isOK(const string &s, const string &pattern) {
        int start = 0;
        int n = (int)pattern.length();
        int m = (int)s.length();
        for (int idxP = 0; idxP < n; ++idxP) {
            bool hasFound = false;
            for (int idxS = start; idxS < m; ++idxS) {
                if (pattern[idxP] == s[idxS]) {
                    hasFound = true;
                    start = idxS + 1;
                    break;
                }
            }
            if (!hasFound) { return false; }
        }
        return true;
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(),
             [](const string &s1, const string &s2) {
                 if (s1.length() != s2.length()) {
                     return s1.length() > s2.length();
                 }
                 return s1 < s2;
        });
        for (const string &str : d) {
            if (isOK(s, str)) { return str; }
        }
        return "";
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

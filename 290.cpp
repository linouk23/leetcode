// 290. Word Pattern - https://leetcode.com/problems/word-pattern

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string tmp;
        stringstream ss(str);
        int index = 0;
        unordered_map<string, char> str_char;
        unordered_map<char, string> char_str;
        while (getline(ss, tmp, ' ')) {
            if (str_char.count(tmp)) {
                if (str_char[tmp] != pattern[index]) {
                    return false;
                }
            } else {
                str_char[tmp] = pattern[index];
            }
            
            if (char_str.count(pattern[index])) {
                if (char_str[pattern[index]] != tmp) {
                    return false;
                }
            } else {
                char_str[pattern[index]] = tmp;
            }
            
            ++index;
        }
        return index == (int)pattern.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

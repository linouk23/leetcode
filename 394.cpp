// 394. Decode String - https://leetcode.com/problems/decode-string

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int index = 0;
public:
    bool is_digit(char ch) {
        return ch >= '0' && ch <= '9';
    }
    
    string decodeString(string s) {
        string result = helper(s);
        return result;
    }
    
    string helper(string s) {
        string result = "";
        while(index < s.length() && s[index] != ']') {
            if (!is_digit(s[index])) {
                result += s[index++];
            } else {
                int num = 0;
                do {
                    num = 10 * num + (s[index++] - '0');
                } while (index < s.length() && s[index] != '[');
                ++index; // jump over '['
                string inner_result = helper(s);
                while (num-- > 0) {
                    result += inner_result;
                }
                ++index; // jump over ']'
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

// 481. Magical String - https://leetcode.com/problems/magical-string

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    char flip(char ch) {
        switch (ch) {
            case '1':
                return '2';
            case '2':
                return '1';
        }
        return '0';
    }
    
    int magicalString(int n) {
        string s = "122";
        int idx = 2;
        while ((int)s.length() < n) {
            switch (s[idx]) {
                case '1':
                    s += string(1, flip(s.back()));
                    break;
                case '2':
                    s += string(2, flip(s.back()));
                    break;
            }
            ++idx;
        }
        return (int)count(s.begin(), s.begin() + n, '1');
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 459. Repeated Substring Pattern - https://leetcode.com/problems/repeated-substring-pattern

#include "bits/stdc++.h"

using namespace std;


//S = SpSp (For example, S has two repeatable block at most)
//If we repeat the string, then SS=SpSpSpSp.
//Destroying first and the last pattern by removing each
//character, we generate a new S2=SxSpSpSy.
//If the string has repeatable pattern inside, S2 should
//have valid S in its string.

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string repeated = s + s;
        repeated.front() = repeated.back() = '#';
        return repeated.find(s) != string::npos;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

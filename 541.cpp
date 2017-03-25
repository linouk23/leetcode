// 541. Reverse String II - https://leetcode.com/problems/reverse-string-ii

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int index = 0; index < s.length(); index += 2*k) {
            reverse(s.begin() + index, min(s.begin() + index + k, s.end()));
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.reverseStr("abcdefg", 2) == "bacdfeg");

    return 0;
}

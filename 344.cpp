// 344. Reverse String - https://leetcode.com/problems/reverse-string

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int n = s.length();
        for (int index = 0; index < n / 2; ++index) {
            swap(s[index], s[n - index - 1]);
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.reverseString("") == "");
    assert(solution.reverseString("a") == "a");
    assert(solution.reverseString("hello") == "olleh");
    assert(solution.reverseString("aadd") == "ddaa");

    return 0;
}

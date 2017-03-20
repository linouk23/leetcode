// 58. Length of Last Word - https://leetcode.com/problems/length-of-last-word

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int R = s.length() - 1;
        while(R >= 0 && s[R] == ' ') {
            --R;
        }

        int length = 0;
        while(R >= 0 && s[R] != ' ') {
            ++length;
            --R;
        }
        return length;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.lengthOfLastWord("hello world") == 5);
    assert(solution.lengthOfLastWord("") == 0);
    assert(solution.lengthOfLastWord("       ") == 0);
    assert(solution.lengthOfLastWord("  world   ") == 5);
    assert(solution.lengthOfLastWord("w") == 1);

    return 0;
}

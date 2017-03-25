// 409. Longest Palindrome - https://leetcode.com/problems/longest-palindrome

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hashtable;

        for (char ch : s) {
            hashtable[ch] += 1;
        }

        int answer = 0;

        bool has_odd_element = false;

        for (const auto &it : hashtable) {
            if (it.second % 2 == 0) {
                answer += it.second;
            } else {
                answer += it.second - 1;
                has_odd_element = true;
            }
        }

        return has_odd_element ? answer + 1 : answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.longestPalindrome("abccccdd") == 7);
    assert(solution.longestPalindrome("") == 0);

    return 0;
}

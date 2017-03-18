// 389. Find the Difference - https://leetcode.com/problems/find-the-difference

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        const int num_of_letters_in_alphabet = 26;
        vector<int> table(num_of_letters_in_alphabet, 0);
        for (char ch : t) {
            table[ch - 'a'] += 1;
        }

        for (char ch : s) {
            table[ch - 'a'] -= 1;
        }

        char answer = 'a';
        for (int index = 0; index < num_of_letters_in_alphabet; ++index) {
            if (table[index] == 1) {
                answer = 97 + index;
                break;
            }
        }

        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;
    assert(solution.findTheDifference("abcd", "abcde") == 'e');
    assert(solution.findTheDifference("aabbccdd", "aabqbccdd") == 'q');
    assert(solution.findTheDifference("aaa", "aaaa") == 'a');
    assert(solution.findTheDifference("", "f") == 'f');

    return 0;
}

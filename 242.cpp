// 242. Valid Anagram - https://leetcode.com/problems/valid-anagram

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashtable;

        for (char ch : s) {
            hashtable[ch] += 1;
        }

        for (char ch : t) {
            hashtable[ch] -= 1;
        }

        for (const auto &it : hashtable) {
            if (it.second != 0) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.isAnagram("anagram", "nagaram") == true);
    assert(solution.isAnagram("rat", "cat") == false);

    return 0;
}

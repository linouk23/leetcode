// 205. Isomorphic Strings - https://leetcode.com/problems/isomorphic-strings

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> hashtable_fst;
        unordered_map<char, char> hashtable_snd;
        for (int index = 0; index < s.length(); ++index) {
            if (hashtable_fst.count(s[index])) {
                if (hashtable_fst[s[index]] != t[index]) {
                    return false;
                }
            } else {
                hashtable_fst[s[index]] = t[index];
            }

            if (hashtable_snd.count(t[index])) {
                if (hashtable_snd[t[index]] != s[index]) {
                    return false;
                }
            } else {
                hashtable_snd[t[index]] = s[index];
            }
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.isIsomorphic("egg", "add") == true);
    assert(solution.isIsomorphic("foo", "bar") == false);
    assert(solution.isIsomorphic("paper", "title") == true);
    assert(solution.isIsomorphic("ab", "aa") == false);

    return 0;
}

// 387. First Unique Character in a String - https://leetcode.com/problems/first-unique-character-in-a-string

#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    int firstUniqChar(string s) {
        const int alphabet_size = 26;
        vector<int> alphabet(alphabet_size);
        for (char ch : s) {
            alphabet[ch - 'a'] += 1;
        }

        for (int index = 0; index < s.length(); ++index) {
            char letter = s[index];
            if (alphabet[letter - 'a'] == 1) {
                return index;
            }
        }

        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.firstUniqChar("leetcode") == 0);
    assert(solution.firstUniqChar("loveleetcode") == 2);

    return 0;
}

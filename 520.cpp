// 520. Detect Capital - https://leetcode.com/problems/detect-capital

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool is_in_lowercase(string &word) {
        for (char ch : word) {
            if (isupper(ch)) {
                return false;
            }
        }
        return true;
    }

    bool is_in_uppercase(string &word) {
        for (char ch : word) {
            if (islower(ch)) {
                return false;
            }
        }
        return true;
    }

    bool detectCapitalUse(string word) {
        if (word.length() == 0) {
            return false;
        }

        string rest_of_word = word.substr(1);
        return (is_in_uppercase(word) || is_in_lowercase(word) ||
                (isupper(word[0]) && is_in_lowercase(rest_of_word)));
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.detectCapitalUse("USA") == true);
    assert(solution.detectCapitalUse("FlaG") == false);
    assert(solution.detectCapitalUse("") == false);
    assert(solution.detectCapitalUse("leetcode") == true);
    assert(solution.detectCapitalUse("Temp") == true);

    return 0;
}

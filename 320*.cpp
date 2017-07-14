// 320. Generalized Abbreviation - https://leetcode.com/problems/generalized-abbreviation

#include "bits/stdc++.h"

using namespace std;

//Given word = "word", return the following list (order does not matter):
//["word", "1ord", "w1rd", "wo1d", "wor1", "2rd",
// "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

class Solution {
private:
    vector<string> result;
    int n;
    void helper(const string &word, string ans_so_far, int start_idx, bool is_last_num) {
        if (start_idx == n) {
            result.emplace_back(ans_so_far);
            return;
        }
        
        // keep this ch = word[start_idx]
        helper(word, ans_so_far + word[start_idx], start_idx + 1, false);
        
        if (is_last_num) { return; }
        // abbr this ch = word[start_idx] + maybe some more ch
        for (int part = 1; part <= n - start_idx; ++part) {
            // word -> 1ord, 2rd, 3d, 4.
            string next = ans_so_far + to_string(part);
            helper(word, next, start_idx + part, true);
        }
    }
public:
    vector<string> generateAbbreviations(string word) {
        n = (int)word.length();
        helper(word, "", 0, false);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

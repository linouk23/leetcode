// 408. Valid Word Abbreviation - https://leetcode.com/problems/valid-word-abbreviation


class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int idx1 = 0, idx2  = 0;
        while (idx1 < word.length() && idx2  < abbr.length()) {
            if (isdigit(abbr[idx2])) {
                if (abbr[idx2] == '0') return false;
                int val = 0;
                while (idx2  < abbr.length() && isdigit(abbr[idx2])) {
                    val = val * 10 + abbr[idx2++] - '0';
                }
                idx1 += val;
            }
            else if (word[idx1++] != abbr[idx2++]) { return false; }
        }
        return idx1 == word.length() && idx2  == abbr.length();
    }
};
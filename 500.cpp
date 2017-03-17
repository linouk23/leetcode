// 500. Keyboard Row - https://leetcode.com/problems/keyboard-row

#include <bits/stdc++.h>

using namespace std;

const int num_of_bits = 32;

class Solution {
private:
    string top_word, middle_word, bottom_word;
    bitset<num_of_bits> top_row, middle_row, bottom_row;

    void fill_in_bitsets() {
        top_word = "qwertyuiop";
        middle_word = "asdfghjkl";
        bottom_word = "zxcvbnm";

        for (char ch : top_word) {
            top_row[ch - 'a'] = 1;
        }

        for (char ch : middle_word) {
            middle_row[ch - 'a'] = 1;
        }

        for (char ch : bottom_word) {
            bottom_row[ch - 'a'] = 1;
        }
    }

public:
    vector<string> findWords(vector<string>& words) {
        fill_in_bitsets();
        vector<string> answer;

        for (const auto &word : words) {
            bitset<num_of_bits> letters;
            for (char ch : word) {
                letters[tolower(ch) - 'a'] = 1;
            }

            if ((letters & top_row).count()    == letters.count() ||
                (letters & middle_row).count() == letters.count() ||
                (letters & bottom_row).count() == letters.count()) {
                answer.push_back(word);
            }
        }

        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<string> input = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> expected_ans = {"Alaska", "Dad"};
    assert(solution.findWords(input) == expected_ans);

    input = {};
    expected_ans = {};
    assert(solution.findWords(input) == expected_ans);

    return 0;
}

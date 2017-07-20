// 418. Sentence Screen Fitting - https://leetcode.com/problems/sentence-screen-fitting

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Idea: create s beforehand.
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s = "";
        for (const string & word : sentence) {
            s += " " + word;
        }
        
        int start = 1;
        for (int r = 0; r < rows; r++, start++) {
            start += cols;
            while (s[start % s.length()] != ' ') { start -= 1; }
        }
        
        start -= 1;
        return start / s.length();
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

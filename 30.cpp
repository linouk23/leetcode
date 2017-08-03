// 30. Substring with Concatenation of All Words - https://leetcode.com/problems/substring-with-concatenation-of-all-words

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (const string &word : words) {
            counts[word] += 1;
        }
        int n = s.length();
        int num_of_words = (int)words.size(), len = (int)words[0].length();
        vector<int> indexes;
        for (int idx = 0; idx < n - num_of_words * len + 1; ++idx) {
            unordered_map<string, int> seen;
            int order = 0;
            for (; order < num_of_words; ++order) {
                string word = s.substr(idx + order * len, len);
                if (counts.count(word)) {
                    seen[word] += 1;
                    if (seen[word] > counts[word]) {
                        break;
                    }
                }
                else { break; }
            }
            if (order == num_of_words) { indexes.emplace_back(idx); }
        }
        return indexes;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

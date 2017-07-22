// 288. Unique Word Abbreviation - https://leetcode.com/problems/unique-word-abbreviation

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (const string& word : dictionary) {
            int n = (int)word.length();
            string abbr = (n < 2) ? word : word[0] + to_string(n) + word[n - 1];
            hashtable[abbr].insert(word);
        }
    }
    
    bool isUnique(string word) {
        int n = (int)word.length();
        string abbr = (n < 2) ? word : word[0] + to_string(n) + word[n - 1];
        return hashtable[abbr].count(word) == hashtable[abbr].size();
    }
private:
    unordered_map<string, unordered_set<string>> hashtable;
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

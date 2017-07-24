// 648. Replace Words - https://leetcode.com/problems/replace-words

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> next;
    string word;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode) { }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto cur = root;
        for (char ch : word) {
            if (!cur->next.count(ch)) {
                cur->next[ch] = new TrieNode;
            }
            cur = cur->next[ch];
        }
        cur->word = word;
    }
    
    /** Returns if the word is in the trie. */
    string search(string word) {
        auto cur = root;
        for (char ch : word) {
            if (!cur->word.empty()) {
                return cur->word;
            }
            if (!cur->next.count(ch)) {
                return word;
            }
            cur = cur->next[ch];
        }
        return word;
    }
    TrieNode* getRoot() {
        return root;
    }
private:
    TrieNode* root;
};

class Solution {
    Trie trie;
public:
    string replaceWords(vector<string> dict, string sentence) {
        for (const auto &word : dict) {
            trie.insert(word);
        }
        string result = "";
        string token;
        char delim = ' ';
        stringstream ss(sentence);
        while(getline(ss, token, delim)) {
            result += trie.search(token);
            result += " ";
        }
        result.pop_back();
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ("the cat was rat by the bat", sol.replaceWords({"cat", "bat", "rat"}, "the cattle was rattled by the battery"));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

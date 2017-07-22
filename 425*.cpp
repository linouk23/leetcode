// 425. Word Squares - https://leetcode.com/problems/word-squares

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<string> words;
};

class Trie {
public:
    Trie() : root(new TrieNode) { }
    
    void insert(string word) {
        auto cur = root;
        for (char ch : word) {
            if (!cur->children.count(ch)) {
                cur->children[ch] = new TrieNode;
            }
            cur->words.emplace_back(word);
            cur = cur->children[ch];
        }
    }
    
    vector<string> startsWith(string prefix) {
        auto cur = root;
        for (char ch : prefix) {
            if (!cur->children.count(ch)) {
                return {};
            }
            cur = cur->children[ch];
        }
        return cur->words;
    }
private:
    TrieNode* root;
};

class Solution {
private:
    Trie trie;
    vector<vector<string>> result;
    bool checkSq(const vector<string> &square) {
        size_t n = square.size();
        size_t row = n - 1;
        for (size_t col = 0; col < n; ++col) {
            if (square[row][col] != square[col][row]) {
                return false;
            }
        }
        return true;
    }
    void helper(vector<string> square, size_t N, unordered_set<string> used) {
        if (square.size() == N) {
            result.emplace_back(square);
            return;
        }
        size_t prefix_len = square.size();
        string prefix = "";
        for (int row = 0; row < prefix_len; ++row) {
            prefix += square[row][prefix_len];
        }
        auto words = trie.startsWith(prefix);
        for (size_t idx = 0; idx < words.size(); ++idx) {
            string word = words[idx];
            if (used.count(word)) { continue; }
            
            used.insert(word);
            square.emplace_back(word);
            helper(square, N, used);
            square.pop_back();
            used.erase(word);
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string> words) {
        for (const auto &word : words) {
            trie.insert(word);
        }
        unordered_set<string> used;
        helper({}, words[0].size(), used);
        return result;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

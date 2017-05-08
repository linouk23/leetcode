// 211. Add and Search Word - Data structure design - https://leetcode.com/problems/add-and-search-word-data-structure-design

#include "bits/stdc++.h"

using namespace std;

struct TrieNode {
    map<char, TrieNode*> next;
    bool is_word = false;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() : root(new TrieNode) {}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto cur = root;
        for (char ch : word) {
            if (!cur->next.count(ch)) {
                cur->next[ch] = new TrieNode;
            }
            cur = cur->next[ch];
        }
        cur->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        bool result = search_helper(root, word, 0);
        return result;
    }
private:
    bool search_helper(TrieNode* start, const string &word, int start_index) {
        auto cur = start;
        for (int index = start_index; index < word.length(); ++index) {
            char ch = word[index];
            if (ch == '.') {
                bool ok = false;
                for (auto it : cur->next) {
                    ok = ok || search_helper(it.second, word, index + 1);
                }
                return ok;
            } else {
                if (!cur->next.count(ch)) {
                    return false;
                }
                cur = cur->next[ch];
            }
        }
        return cur->is_word;
    }
    TrieNode* root;
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

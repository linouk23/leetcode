// 208. Implement Trie (Prefix Tree) - https://leetcode.com/problems/implement-trie-prefix-tree

#include "bits/stdc++.h"

using namespace std;

struct TrieNode {
    map<char, TrieNode*> next;
    bool is_end = false;
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
        cur->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto cur = root;
        for (char ch : word) {
            if (!cur->next.count(ch)) {
                return false;
            }
            cur = cur->next[ch];
        }
        return cur->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto cur = root;
        for (char ch : prefix) {
            if (!cur->next.count(ch)) {
                return false;
            }
            cur = cur->next[ch];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

// 14. Longest Common Prefix - https://leetcode.com/problems/longest-common-prefix

#include "bits/stdc++.h"

using namespace std;

struct TrieNode {
    map<char, TrieNode*> next;
};

class Trie {
public:
    Trie() : root(new TrieNode) {}
    void insert(const string &word) {
        auto cur = root;
        for (char ch : word) {
            if (!cur->next.count(ch)) {
                cur->next[ch] = new TrieNode;
            }
            cur = cur->next[ch];
        }
        cur->next['#'] = new TrieNode;
    }
    string lengthOfCommonPrefix() {
        string result;
        auto cur = root;
        while (cur != nullptr && (int)cur->next.size() == 1) {
            auto it = cur->next.begin();
            char ch = it->first;
            if (ch == '#') { break; }
            result += ch;
            cur = cur->next[ch];
        }
        return result;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for (const auto &str : strs) {
            trie.insert(str);
        }
        return trie.lengthOfCommonPrefix();
    }
private:
    Trie trie;
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

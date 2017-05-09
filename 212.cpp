// 212. Word Search II - https://leetcode.com/problems/word-search-ii

#include "bits/stdc++.h"

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> next;
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
    TrieNode* getRoot() {
        return root;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    void dfs(int row, int column, TrieNode* node, string word) {
        auto is_valid_pair = [this, &node](int row, int column) -> bool {
            return row >= 0 && column >= 0 &&
                   row < n  && column < m &&
//                   board_[row][column] != '#' &&
                   node->next.count(board_[row][column]);
        };
        if (!is_valid_pair(row, column)) { return; }
        char ch = board_[row][column];
        board_[row][column] = visited;
        
        word += ch;
        node = node->next[ch];
        if (node->is_end)  { result_set.insert(word); }
        
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, 1, -1, 0};
        for (int dir = 0; dir < 4; ++dir) {
            int new_row = row + dy[dir];
            int new_column = column + dx[dir];
            dfs(new_row, new_column, node, word);
        }
        // Like pop_back()
        board_[row][column] = ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        board_ = board;
        n = (int)board.size();
        m = (int)board[0].size();
        for (const auto &word : words) {
            trie.insert(word);
        }
        
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < m; ++column) {
                dfs(row, column, trie.getRoot(), "");
            }
        }
        
        return {result_set.begin(), result_set.end()};
    }
private:
    vector<vector<char> > board_;
    unordered_set<string> result_set;
    int n, m;
    char visited = '#';
    Trie trie;
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

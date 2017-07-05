// 187. Repeated DNA Sequences - https://leetcode.com/problems/repeated-dna-sequences

#include "bits/stdc++.h"

using namespace std;

//struct TrieNode {
//    bool is_word = false;
//    unordered_map<char, TrieNode*> children;
//};
//
//class Trie {
//private:
//    TrieNode* root;
//    void add_word(const string & str) {
//        auto cur = root;
//        for (char ch : str) {
//            if (!cur->children.count(ch)) {
//                cur->children[ch] = new TrieNode();
//            }
//            cur = cur->children[ch];
//        }
//        cur->is_word = true;
//    }
//    bool find_word(const string & str) {
//        auto cur = root;
//        for (char ch : str) {
//            if (!cur->children.count(ch)) {
//                return false;
//            }
//            cur = cur->children[ch];
//        }
//        return cur->is_word;
//    }
//public:
//    Trie() { root = new TrieNode(); }
//    bool is_already_present(const string & str) {
//        if (!find_word(str)) {
//            add_word(str);
//            return false;
//        }
//        return true;
//    }
//};
//
//class Solution {
//private:
//    Trie* trie;
//public:
//    vector<string> findRepeatedDnaSequences(string s) {
//        trie = new Trie();
//        int n = (int)s.length();
//        int len = 10;
//        unordered_set<string> result;
//        for (int start = 0; start + len - 1 < n; ++start) {
//            string dna = s.substr(start, len);
//            if (!result.count(dna) && trie->is_already_present(dna)) {
//                result.insert(dna);
//            }
//        }
//        // Trick.
//        return {result.begin(), result.end()};
//    }
//};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> let_to_bits = {
            {'A', 0},
            {'C', 1},
            {'G', 2},
            {'T', 3},
        };
        unordered_set<int> int_words;
        unordered_set<string> result;
        int len = 10;
        int n = (int)s.length();
        for (int start = 0; start + len - 1 < n; ++start) {
            string dna = s.substr(start, len);
            if (result.count(dna)) { continue; }
            int int_from_dna = 0;
            for (char ch : dna) {
                int_from_dna <<= 2;
                int_from_dna |= let_to_bits[ch];
            }
            if (int_words.count(int_from_dna)) {
                result.insert(dna);
            } else {
                int_words.insert(int_from_dna);
            }
        }
        return {result.begin(), result.end()};
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

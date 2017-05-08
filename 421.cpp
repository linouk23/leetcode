// 421. Maximum XOR of Two Numbers in an Array - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array

#include "bits/stdc++.h"

using namespace std;

const int ALPHABET_SIZE = 2;

struct TrieNode {
    vector<TrieNode*> next;
    bool is_finish = false;
    TrieNode() {
        next.assign(ALPHABET_SIZE, nullptr);
    }
};

class Trie {
public:
    Trie() { root = new TrieNode(); }
    void insert(string &str) {
        auto cur = root;
        for (char ch : str) {
            int digit = ch - '0';
            if (cur->next[digit] == nullptr) {
                cur->next[digit] = new TrieNode();
            }
            cur = cur->next[digit];
        }
        cur->is_finish = true;
    }
    int find_max_xor_for(int number) {
        string binary = bitset<32>(number).to_string();
        int max_xor_result = 0;
        auto cur = root;
        for (int index = 0; index < 32; ++index) {
            int digit = binary[index] - '0';
            int desirable_digit = (digit == 0) ? 1 : 0;
            int digit_in_paired_num = (cur->next[desirable_digit]) ? desirable_digit : digit;
            if (digit + digit_in_paired_num == 1) {
                max_xor_result += (1 << (31 - index));
            }
            cur = cur->next[digit_in_paired_num];
        }
        return max_xor_result;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        build_trie_from(nums);
        int max_xor = -1;
        for (int number : nums) {
            max_xor = max(max_xor, find_max_xor_for(number));
        }
        return max_xor;
    }
private:
    Trie trie;
    void build_trie_from(vector<int>& nums) {
        for (int number : nums) {
            string binary = bitset<32>(number).to_string();
            trie.insert(binary);
        }
    }
    int find_max_xor_for(int number) {
        int result = trie.find_max_xor_for(number);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

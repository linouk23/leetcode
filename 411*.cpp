// 588. Design In-Memory File System - https://leetcode.com/problems/design-in-memory-file-system

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// https://discuss.leetcode.com/topic/61457/c-bit-manipulation-dfs-solution

// The key idea of my solution is to preprocess the dictionary to transfer all 
// the words to bit sequences (int):
// Pick the words with same length as target string from the dictionary and
// compare the characters with target. If the characters are different, set 
// the corresponding bit to 1, otherwise, set to 0.
// Ex: "abcde", ["abxdx", "xbcdx"] => [00101, 10001]

// The problem is now converted to find a bit mask that can represent the shortest
// abbreviation, so that for all the bit sequences in dictionary,
// mask & bit sequence > 0.
// Ex: for [00101, 10001], the mask should be [00001]. if we mask the target 
// string with it, we get "****e" ("4e"), which is the abbreviation we are
// looking for.

// To find the bit mask, we need to perform DFS with some optimizations. 
// But which bits should be checked? We can perform "or" operation for all
// the bit sequences in the dictionary and do DFS for the "1" bits in the result.
// Ex: 00101 | 10001 = 10101, so we only need to take care of the 1st, 3rd,
// and 5th bit.

class Solution {
    int n, cand, bn, minlen, minab;
    vector<int> dict;
    
    // Return the length of abbreviation given bit sequence
    int abbrLen(int mask) {
        int count = 0;
        for (int b = 1; b < bn;) {
            if ((mask & b) == 0)
                for (; b < bn and (mask & b) == 0; b <<= 1);
            else b <<= 1;
            count ++;
        }
        return count;
    }

    // DFS backtracking
    void dfs(int bit, int mask) {
        int len = abbrLen(mask);
        if (len >= minlen) return;
        bool match = true;
        for (auto d : dict) {
            if ((mask & d) == 0) {
                match = false;
                break;
            }
        }
        if (match) {
            minlen = len;
            minab = mask;
        }
        else
            for (int b = bit; b < bn; b <<= 1)
                if (cand & b) dfs(b << 1, mask + b);
    }

public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        n = target.size(), bn = 1 << n, cand = 0, minlen = INT_MAX;
        string res;
        
        // Preprocessing with bit manipulation
        for (auto w : dictionary) {
            int word = 0;
            if (w.size() != n) continue;
            for (int i = n-1, bit = 1; i >= 0; --i, bit <<= 1)
                if (target[i] != w[i]) word += bit;
            dict.push_back(word);
            cand |= word;
        }
        dfs(1, 0);

        // Reconstruct abbreviation from bit sequence
        for (int i = n-1, pre = i; i >= 0; --i, minab >>= 1) {
            if (minab & 1) {
                if (pre-i > 0) res = to_string(pre-i) + res;
                pre = i - 1;
                res = target[i] + res;
            }
            else if (i == 0) res = to_string(pre-i+1) + res;
        }
        return res;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
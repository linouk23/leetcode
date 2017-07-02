// 318. Maximum Product of Word Lengths - https://leetcode.com/problems/maximum-product-of-word-lengths

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;
        int n = (int)words.size();
        vector<int> num_words(n);
        for (int idx = 0; idx < n; ++idx) {
            string word = words[idx];
            for (char ch : word) {
                num_words[idx] |= (1 << (ch - 'a'));
            }
        }
        for (int idx1 = 0; idx1 < n; ++idx1) {
            for (int idx2 = idx1 + 1; idx2 < n; ++idx2) {
                if (num_words[idx1] & num_words[idx2]) { continue; }
                result = max(result, int(words[idx1].size() * words[idx2].size()));
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

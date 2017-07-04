// 472. Concatenated Words - https://leetcode.com/problems/concatenated-words

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> hashset(words.begin(), words.end());
        hashset.erase("");
        vector<string> result;
        for (const auto &word : hashset) {
            int n = (int)word.length();
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            for (int start = 0; start < n; ++start) {
                if (dp[start] == false) { continue; }
                for (int len = 1; start + len - 1 < n; ++len) {
                    if (len == n) { continue; }
                    int next_start = start + len;
                    if (hashset.count(word.substr(start, len))) {
                        dp[next_start] = true;
                    }
                    if (dp[n]) {
                        break;
                    }
                }
            }
            if (dp[n]) {
                result.emplace_back(word);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

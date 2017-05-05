// 139. Word Break - https://leetcode.com/problems/word-break

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        unordered_set<string> hashset(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for (int start = 1; start <= s.length(); ++start) {
            if (!dp[start - 1]) { continue; }
            for (int len = 1; len + start - 1 <= s.length(); ++len) {
                if (hashset.count(s.substr(start - 1, len))) {
                    dp[start + len - 1] = true;
                }
            }
        }
        
        return dp[s.length()];
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

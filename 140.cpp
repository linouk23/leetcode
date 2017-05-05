// 140. Word Break II - https://leetcode.com/problems/word-break-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    set<vector<string> > result_set;
public:
    void helper(string& s, unordered_set<string>& hashset, vector<bool>& dp, int index, vector<string> cur) {
        if (index < 0) {
            return;
        }
        if (index == 0) {
            result_set.insert(cur);
            return;
        }
        if (!dp[index]) {
            return;
        }
        for (int len = index; len >= 0; --len) {
            if (hashset.count(s.substr(index - len, len))) {
                cur.emplace_back(s.substr(index - len, len));
                helper(s, hashset, dp, index - len, cur);
                cur.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
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
        helper(s, hashset, dp, (int)s.length(), {});
        vector<string> result;
        for (const auto &vec : result_set) {
            string answer;
            for (auto word_it = vec.rbegin(); word_it != vec.rend(); ++word_it) {
                answer += *word_it;
                answer += " ";
            }
            answer.pop_back();
            result.emplace_back(answer);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

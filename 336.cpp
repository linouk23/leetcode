// 336. Palindrome Pairs - https://leetcode.com/problems/palindrome-pairs

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Trick:
// Partition the word into left and right, and see
// 1) if there exists a candidate in map equals the left
// side of current word, and right side of current word is
// palindrome, so concatenate(current word, candidate) forms a pair:
// left | right | candidate.
// 2) same for checking the right side of current word:
// candidate | left | right.
// "lls", "s" -> "slls"
class Solution {
private:
    bool isPalindrome(const string& s) {
        size_t n = s.length();
        for (int idx = 0; idx < n / 2; ++idx) {
            if (s[idx] != s[n - idx - 1]) { return false; }
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        if (words.size() < 2) return result;
        unordered_map<string, int> str2idx;
        for (int idx = 0; idx < (int)words.size(); ++idx){
            str2idx[words[idx]] = idx;
        }
        for (int idx = 0; idx < words.size(); ++idx) {
            auto word = words[idx];
            for (int len = 0; len <= word.size(); ++len) {
                // <= to handle an empty string
                string prefix = word.substr(0, len);
                string suffix = word.substr(len);
                if (isPalindrome(prefix)) {
                    string rev_suf(suffix.rbegin(), suffix.rend());
                    if (str2idx.count(rev_suf) && str2idx[rev_suf] != idx ){
                        result.push_back({str2idx[rev_suf], idx});
                    }
                }
                if (isPalindrome(suffix)) {
                    string rev_pre(prefix.rbegin(), prefix.rend());
                    if (str2idx.count(rev_pre) && str2idx[rev_pre] != idx &&
                       !suffix.empty()) {
                        result.push_back({idx, str2idx[rev_pre]});
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// 291. Word Pattern II - https://leetcode.com/problems/word-pattern-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    bool helper(int cur_idx_p, int cur_idx_s, unordered_map<char, string> chToStr, const string &pattern, const string &str) {
        if (cur_idx_s == str.length()) { return cur_idx_p == pattern.length(); }
        if (cur_idx_p == pattern.length()) { return cur_idx_s == str.length(); }
        
        if (chToStr.count(pattern[cur_idx_p])) {
            string word = chToStr[pattern[cur_idx_p]];
            int len = (int)word.length();
            if (str.substr(cur_idx_s, len) == word) {
                return helper(cur_idx_p + 1, cur_idx_s + len, chToStr, pattern, str);
            }
            return false;
        }
        
        for (int finish = cur_idx_s; finish < str.length(); ++finish) {
            int len = finish - cur_idx_s + 1;
            string substr = str.substr(cur_idx_s, len);
            chToStr[pattern[cur_idx_p]] = substr; // push_back()
            if (helper(cur_idx_p + 1, finish + 1, chToStr, pattern, str)) {
                return true;
            }
            chToStr.erase(pattern[cur_idx_p]); // pop_back()
        }
        return false;
    }
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> chToStr;
        return helper(0, 0, chToStr, pattern, str);
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_TRUE(sol.wordPatternMatch("abab", "redblueredblue"));
    EXPECT_TRUE(sol.wordPatternMatch("aaaa", "asdasdasdasd"));
    EXPECT_TRUE(sol.wordPatternMatch("a", "asdasdasdasd"));
    EXPECT_FALSE(sol.wordPatternMatch("aabb", "xyzabcxzyabc"));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

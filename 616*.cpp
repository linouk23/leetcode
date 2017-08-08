// 616. Add Bold Tag in String - https://leetcode.com/problems/add-bold-tag-in-string

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string addBoldTag(string s, vector<string> dict) {
        string result = "";
        int n = (int)s.length();
        deque<bool> isBold(n);
        int lastBold = -1;
        for (int idx = 0; idx < n; ++idx){
            for (const string &word : dict){
                int len = (int)word.length();
                if (idx + len <= n && s.substr(idx, len) == word)
                    lastBold = max(lastBold, idx + len - 1);
            }
            
            isBold[idx] = (lastBold >= idx);
        }
        
        for (int idx = 0; idx < n; ++idx){
            if (!isBold[idx]) {
                result += s[idx];
            } else {
                int curIdx = idx;
                while (curIdx < n && isBold[curIdx]) {
                    ++curIdx;
                }
                int len = curIdx - idx;
                result += "<b>" + s.substr(idx, len) + "</b>";
                idx = curIdx - 1;
            }
        }
        
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ("<b>abc</b>xyz<b>123</b>", sol.addBoldTag("abcxyz123", {"abc","123"}));
    EXPECT_EQ("<b>aaabbc</b>c", sol.addBoldTag("aaabbcc", {"aaa","aab","bc"}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

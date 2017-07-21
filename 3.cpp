// 3. Longest Substring Without Repeating Characters - https://leetcode.com/problems/longest-substring-without-repeating-characters

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = (int)s.length();
        int L = 0, R = 0;
        unordered_map<char, int> countTable;
        for (char ch : s) {
            countTable[ch] = 1;
        }
        int result = 0;
        while (R < n) {
            char ch = s[R];
            if (countTable[ch]) {
                countTable[ch] -= 1;
            } else {
                while (countTable[ch] == 0) {
                    countTable[s[L++]] += 1;
                }
                countTable[ch] -= 1;
            }
            result = max(result, R - L + 1);
            R += 1;
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(3, sol.lengthOfLongestSubstring("abcabcbb"));
    EXPECT_EQ(1, sol.lengthOfLongestSubstring("bbbbbbbb"));
    EXPECT_EQ(3, sol.lengthOfLongestSubstring("pwwkew"));
    EXPECT_EQ(3, sol.lengthOfLongestSubstring("abca"));
}

TEST(SolutionTest, Empty) {
    Solution sol;
    EXPECT_EQ(0, sol.lengthOfLongestSubstring(""));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

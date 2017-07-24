// 424. Longest Repeating Character Replacement - https://leetcode.com/problems/longest-repeating-character-replacement

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Idea:
// we can apply the at most k changes constraint
// and maintain a sliding window such that
// (length of substring - number of times
// of the maximum occurring character in the substring) <= k
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> countTable;
        int n = (int)s.length();
        int L = 0, R = 0;
        int result = 0;
        int maxCount = 0;
        while (R < n) {
            char ch = s[R];
            countTable[ch] += 1;
            maxCount = max(maxCount, countTable[ch]);
            // Trick:
            // (sum == len) - mostFreq <= k (all the rest symbol
            // counts on [L, R])
            // Replace any letter in the string with another
            // letter at most k times
            int len = R - L + 1;
            while (len - maxCount > k) {
                ch = s[L++];
                countTable[ch] -= 1;
                for (ch = 'A'; ch <= 'Z'; ++ch) {
                    maxCount = max(maxCount, countTable[ch]);
                }
                len = R - L + 1;
            }
            // len - maxCount <= k, which is OK
            result = max(result, len);
            ++R;
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(4, sol.characterReplacement("ABAB", 2));
    EXPECT_EQ(4, sol.characterReplacement("AABABBA", 1));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

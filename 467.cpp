// 467. Unique Substrings in Wraparound String - https://leetcode.com/problems/unique-substrings-in-wraparound-string

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// https://discuss.leetcode.com/topic/70658/concise-java-solution-using-dp
// Idea: dp
// 1. The max number of unique substring ends with a letter equals to the
// length of max contiguous substring ends with that letter. Example
// "abcd", the max number of unique substring ends with 'd' is 4, apparently
// they are "abcd", "bcd", "cd" and "d".

// 2. If there are overlapping, we only need to consider the longest
// one because it covers all the possible substrings.
// Example: "abcdbcd", the max number of unique substring ends with 'd'
// is 4 and all substrings formed by the 2nd "bcd" part are covered in
// the 4 substrings already.
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p.empty()) { return 0; }
        const int ALPHABET_SIZE = 26;
        // Let dp[ch] be the max length of conseq seq
        // which last symbol is ch.
        vector<int> dp(ALPHABET_SIZE, 0);
        
        int n = (int)p.length();
        int conseq_length = 1;
        dp[p[0] - 'a'] = conseq_length;
        for (int idx = 1; idx < n; ++idx) {
            char cur_letter  = p[idx];
            char prev_letter = p[idx - 1];
            // "ba" or "za"
            int diff = cur_letter - prev_letter;
            if (diff == 1 || diff == -25) {
                conseq_length += 1;
            } else {
                conseq_length = 1;
            }
            dp[cur_letter - 'a'] = max(dp[cur_letter - 'a'], conseq_length);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(1, sol.findSubstringInWraproundString("a"));
    EXPECT_EQ(2, sol.findSubstringInWraproundString("cac"));
    EXPECT_EQ(6, sol.findSubstringInWraproundString("zab"));
}

TEST(SolutionTest, Empty) {
    Solution sol;
    EXPECT_EQ(0, sol.findSubstringInWraproundString(""));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

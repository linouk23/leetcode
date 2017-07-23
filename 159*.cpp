// 159. Longest Substring with At Most Two Distinct Characters - https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> counts;
        int k = 2;
        int count = k;
        int n = (int)s.length();
        int L = 0, R = 0;
        int result = 0;
        while (R < n) {
            char ch = s[R];
            if (counts[ch]++ == 0) {
                count -= 1;
            }
            // Works for k = 0, R < L:)
            while (count < 0) {
                if (counts[s[L++]]++ == 0) {
                    count += 1;
                }
            }
            result = max(result, R - L + 1);
            ++R;
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(3, sol.lengthOfLongestSubstringTwoDistinct("eceba"));
    EXPECT_EQ(5, sol.lengthOfLongestSubstringTwoDistinct("aaaaa"));
    EXPECT_EQ(2, sol.lengthOfLongestSubstringTwoDistinct("ab"));
}

TEST(SolutionTest, Empty) {
    Solution sol;
    EXPECT_EQ(0, sol.lengthOfLongestSubstringTwoDistinct(""));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

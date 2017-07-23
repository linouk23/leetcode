// 340. Longest Substring with At Most K Distinct Characters - https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> counts;
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
    EXPECT_EQ(3, sol.lengthOfLongestSubstringKDistinct("eceba", 2));
    EXPECT_EQ(5, sol.lengthOfLongestSubstringKDistinct("aaaaa", 2));
    EXPECT_EQ(5, sol.lengthOfLongestSubstringKDistinct("aaaaa", 1));
    EXPECT_EQ(0, sol.lengthOfLongestSubstringKDistinct("aaaaa", 0));
}

TEST(SolutionTest, Empty) {
    Solution sol;
    EXPECT_EQ(0, sol.lengthOfLongestSubstringKDistinct("", 10));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

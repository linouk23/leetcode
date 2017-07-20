// 186. Reverse Words in a String II - https://leetcode.com/problems/reverse-words-in-a-string-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = (int)s.length(), L = 0, R = 0;
        while (R < n) {
            while (R < n && !isspace(s[R])) { R += 1; };
            reverse(s.begin() + L, s.begin() + R);
            R += 1;
            L = R;
        }
        return s;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ("blue is sky the", sol.reverseWords("the sky is blue"));
}

TEST(SolutionTest, Empty) {
    Solution sol;
    EXPECT_EQ("", sol.reverseWords(""));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

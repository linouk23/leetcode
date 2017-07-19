// 161. One Edit Distance - https://leetcode.com/problems/one-edit-distance

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// There're 3 possibilities to satisfy one edit distance apart:
// 1) Replace 1 char:
// s: a B c
// t: a D c
// 2) Delete 1 char from s:
// s: a D  b c
// t: a    b c
// Trick: insert == reverse(delete)
// 3) Delete 1 char from t == Insert 1 char into s:
// s: a   b c
// t: a D b c


class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = (int)s.length(), m = (int)t.length();
        for (int idx = 0; idx < min(n, m); ++idx) {
            if (s[idx] == t[idx]) { continue; }
            if (n == m) {       // 1. Replace
                return s.substr(idx + 1) == t.substr(idx + 1);
            } else if (n > m) { // 2. Delete from s, s.length() = n
                return s.substr(idx + 1) == t.substr(idx);
            } else {            // 3. Delete from t, t.length() = m
                return s.substr(idx) == t.substr(idx + 1);
            }
        }
        // Previous chars are the same, the only opportunity
        // is deleting/inserting the last symbol
        return abs(n - m) == 1;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_FALSE(sol.isOneEditDistance("abcd", "abcd"));
    EXPECT_TRUE(sol.isOneEditDistance("abc", "abd"));
    EXPECT_TRUE(sol.isOneEditDistance("abDc", "abc"));
    EXPECT_TRUE(sol.isOneEditDistance("abc", "abDc"));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

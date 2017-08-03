// 214. Shortest Palindrome - https://leetcode.com/problems/shortest-palindrome

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Trick:
// According to the question, we are allowed to insert the characters only
// at the beginning of the string. Hence, we can find the largest segment
// from the beginning that is a palindrome, and we can then easily reverse
// the remaining segment and append to the beginning. This must be the
// required answer as no shorter palindrome could be found
// than this by just appending at the beginning.

class Solution {
private:
    vector<int> prefix_function(const string &s) {
        size_t n = s.length();
        vector<int> pi(n);
        for (int idx = 1; idx < n; ++idx) {
            int len = pi[idx - 1];
            while (len > 0 && s[idx] != s[len]) { len = pi[len - 1]; }
            if (s[idx] == s[len]) { ++len; }
            pi[idx] = len;
        }
        return pi;
    }
public:
    string shortestPalindrome(string s) {
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        string kmp_s = s + "#" + reversed;
        auto prefix = prefix_function(kmp_s);
        // abcabcd
        // 0001230
        // max len(prefix == suffix)
        size_t len = s.length() - prefix.back();
        // abad#daba
        //         ?
        // ? - len of palindrome from the beginning, and then reverse
        // the remaining segment and append to the beginning.
        return reversed.substr(0, len) + s;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ("aaacecaaa", sol.shortestPalindrome("aacecaaa"));
    EXPECT_EQ("dcbabcd", sol.shortestPalindrome("abcd"));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

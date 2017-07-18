// 395. Longest Substring with At Least K Repeating Characters - https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Phil Jackson
class Solution {
private:
    struct Result {
        char ch;
        int freq;
    };
    Result findMostInfreqCh(const string &s) {
        unordered_map<char, int> countTable;
        for (char ch : s) {
            countTable[ch] += 1;
        }
        Result result = { 't', INT_MAX };
        for (const auto &p : countTable) {
            if (p.second < result.freq) {
                tie(result.ch, result.freq) = p;
            }
        }
        return result;
    }
public:
    int longestSubstring(string s, int k) {
        int n = (int)s.length();
        if (n < k) { return 0; }
        
        // Split by a least frequent character (because it
        // will always be too infrequent and thus can't be
        // part of any ok substring) and make the most out
        // of the splits.
        auto infreqChAndFreq = findMostInfreqCh(s);
        
        if (infreqChAndFreq.freq >= k) {
            return n;
        }
        
        int result = 0;
        stringstream ss(s);
        string part;
        while (getline(ss, part, infreqChAndFreq.ch)) {
            result = max(result, longestSubstring(part, k));
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(3, sol.longestSubstring("aaabb", 3));
    EXPECT_EQ(5, sol.longestSubstring("ababbc", 2));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

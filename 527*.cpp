// 527. Word Abbreviation - https://leetcode.com/problems/word-abbreviation

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = (int)dict.size();
        vector<string> result(n);
        // lens of prefixes
        vector<int> pre(n, 1);
        for (int idx = 0; idx < n; ++idx) {
            result[idx] = abbreviate(dict[idx], pre[idx]);
        }
        // If there are any conflict, that is more than one
        // words share the same abbreviation, a longer prefix
        // is used instead of only the first character until
        // making the map from word to abbreviation become unique.
        for (int idx = 0; idx < n; ++idx) {
            bool hasConflicts = true;
            while (hasConflicts) {
                unordered_set<int> conflicts_idx;
                for (int j = idx + 1; j < n; ++j) {
                    if (result[j] == result[idx]) { conflicts_idx.insert(j); }
                }
                // There're no conflicts.
                if (conflicts_idx.empty()) break;
                conflicts_idx.insert(idx);
                for (int conflict_idx : conflicts_idx) {
                    result[conflict_idx] = abbreviate(dict[conflict_idx],
                                                      ++pre[conflict_idx]);
                }
            }
        }
        return result;
    }
private:
    string abbreviate(string s, int k) {
        return (k >= s.size() - 2) ? s : s.substr(0, k) + to_string(s.size() - k - 1) + s.back();
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

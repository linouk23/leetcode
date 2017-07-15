// 249. Group Shifted Strings - https://leetcode.com/problems/group-shifted-strings

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string> strings) {
        unordered_map<string, multiset<string>> hashtable;
        for (const auto &str : strings) {
            hashtable[shift(str)].insert(str);
        }
        vector<vector<string>> result;
        for (auto &p : hashtable) {
            // p.second == group
            result.push_back({p.second.begin(), p.second.end()});
        }
        return result;
    }
private:
    string shift(const string& s) {
        string key;
        int n = (int)s.length();
        for (int idx = 1; idx < n; ++idx) {
            int diff = s[idx] - s[idx - 1];
            if (diff < 0) diff += 26;
            key += 'a' + diff + ',';
        }
        return key;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    vector<vector<string>> expected = {
        {"a", "z"},
        {"az", "ba"},
        {"acef"},
        {"abc", "bcd", "xyz"},
    };
    EXPECT_EQ(expected, sol.groupStrings({"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

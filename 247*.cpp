// 247. Strobogrammatic Number II - https://leetcode.com/problems/strobogrammatic-number-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    unordered_map<char, char> m = {
        {'0', '0'},
        {'1', '1'},
        {'8', '8'},
        {'6', '9'},
        {'9', '6'},
    };
public:
    vector<string> findStrobogrammatic(int n) {
        vector<vector<string>> result(n + 10);
        result[0] = {""};
        result[1] = {"0", "1", "8"};
        for (int idx = 2; idx <= n; ++idx) {
            for (const auto &str : result[idx - 2]) {
                for (const auto &p : m) {
                    if (idx == n && p.first == '0') { continue; }
                    result[idx].emplace_back(p.first + str + p.second);
                }
            }
        }
        return result[n];
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

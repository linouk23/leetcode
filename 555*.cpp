// 555. Split Concatenated Strings - https://leetcode.com/problems/split-concatenated-strings

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int n;
    string result = "";
    void solve(vector<string>& strs, int start, bool shouldReverse) {
        string curStr = strs[start];
        if (shouldReverse) { reverse(curStr.begin(), curStr.end()); }
        int n = (int)curStr.size();
        string rightPart = "", leftPart = "";
        for (int right = start + 1; right < n; ++right) {
            rightPart += strs[right];
        }
        for (int left = 0; left < start; ++left) {
            leftPart += strs[left];
        }
        for (int k = 0; k < n; ++k) {
            string newOne = curStr.substr(k) + rightPart +
                            leftPart + curStr.substr(0, k);
            result = (result.empty()) ? newOne : max(result, newOne);
        }
    }

    void findMaxStrings(vector<string>& strs) {
        for (int idx = 0; idx < n; ++idx) {
            string revStr = strs[idx];
            reverse(revStr.begin(), revStr.end());
            strs[idx] = strs[idx] > revStr ? strs[idx] : revStr;
        }
    }

    string splitLoopedString(vector<string>& strs) {
        n = (int)strs.size();
        if (n == 0) return "";
        findMaxStrings(strs);
        bool shouldReverse = true;
        for (int idx = 0; idx < n; ++idx) {
            solve(strs, idx, shouldReverse);
            solve(strs, idx, !shouldReverse);
        }
        return result;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

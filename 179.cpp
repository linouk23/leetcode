// 179. Largest Number - https://leetcode.com/problems/largest-number

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> str_nums;
        for (int num : nums) {
            str_nums.emplace_back(to_string(num));
        }
        sort(str_nums.begin(), str_nums.end(), []
             (const string &s1, const string &s2) { return s1 + s2 > s2 + s1; });
        string result;
        result = accumulate(str_nums.begin(), str_nums.end(), string(""));
        reverse(result.begin(), result.end());
        while (result.back() == '0' && !result.empty()) {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result.empty() ? "0" : result;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

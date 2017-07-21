// 402. Remove K Digits - https://leetcode.com/problems/remove-k-digits

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Idea: turn bruteforce O(NK) into O(N) using stack.
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = (int)num.length();
        for (int idx = 0; idx < n; ++idx) {
            char digit = num[idx];
            while (!st.empty() && st.top() > digit &&
                k > 0) {
                st.pop();
                k -= 1;
            }
            st.push(digit);
        }
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        while (!result.empty() && result.back() == '0') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        while (!result.empty() && k > 0) {
            result.pop_back();
            k -= 1;
        }
        return result.empty() ? "0" : result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ("1219", sol.removeKdigits("1432219", 3));
    EXPECT_EQ("200", sol.removeKdigits("10200", 1));
    EXPECT_EQ("0", sol.removeKdigits("10", 2));
    EXPECT_EQ("0", sol.removeKdigits("9", 1));
    EXPECT_EQ("0", sol.removeKdigits("1234567890", 9));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

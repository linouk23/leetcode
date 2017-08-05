// 224. Basic Calculator - https://leetcode.com/problems/basic-calculator

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Trick:
// Calculate the result within parenthesis in 'result'
// Think about the case when they're nested.
// Keep result so far in stack.
// 2 + 3 + 5 - (10 + 8)
// [10, -1==sign] and result = 18
// [10, -18] -> [-8]
class Solution {
public:
    int calculate(string s) {
        int result = 0, num = 0, sign = 1;
        string p = s + " ";
        stack<int> st; // store terms
        // 2 + 3 + 5 - (10 + 8)
        // [10, -1==sign] and result = 18
        // [10, -18] -> [-8]
        for (char ch : s) {
            if (isdigit(ch)) {
                num = 10 * num + ch - '0';
            } else if (ch == '+') {
                result += sign * num;
                sign = 1;
                num = 0;
            } else if (ch == '-') {
                result += sign * num;
                sign = -1;
                num = 0;
            } else if (ch == '(') {
                st.push(result);
                st.push(sign);
                num = 0;
                // Result for the value
                // in parenthesis
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                // Think about nested parenthesis
                result += num * sign;
                sign = st.top(); st.pop();
                result *= sign;
                result += st.top(); st.pop();
                num = 0;
            }
        }
        if (num != 0) { result += num * sign; }
        if (result != 0) { st.push(result); }
        result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(2, sol.calculate("1 + 1"));
    EXPECT_EQ(3, sol.calculate(" 2-1 + 2 "));
    EXPECT_EQ(23, sol.calculate("(1+(4+5+2)-3)+(6+8)"));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

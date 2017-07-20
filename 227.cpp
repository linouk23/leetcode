// 227. Basic Calculator II - https://leetcode.com/problems/basic-calculator-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        if (s.empty()) { return 0; }
        stack<int> st;
        int num = 0;
        char sign = '+';
        s += sign;
        for (char ch : s) {
            if (ch == ' ') {
                continue;
            }

            if (isdigit(ch)) {
                num = 10 * num + (ch - '0');
            } else {
                // 10+, when meet + it's time to make +? 10
                if (sign == '-') {
                    st.push(-num);
                } else if (sign == '+') {
                    st.push(num);
                } else if (sign == '*') {
                    int top_num = st.top(); st.pop();
                    st.push(top_num * num);
                } else {
                    int top_num = st.top(); st.pop();
                    st.push(top_num / num);
                }
                // Reset:
                sign = ch;
                num = 0;
            }
        }
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(7, sol.calculate("3+2*2"));
    EXPECT_EQ(1, sol.calculate(" 3/2 "));
    EXPECT_EQ(5, sol.calculate(" 3+5 / 2 "));
}

TEST(SolutionTest, Empty) {
    Solution sol;
    EXPECT_EQ(0, sol.calculate(""));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

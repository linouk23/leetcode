// 439. Ternary Expression Parser - https://leetcode.com/problems/ternary-expression-parser

#include "bits/stdc++.h"

using namespace std;

// Iterate the expression from tail, whenever encounter a character
// before '?', calculate the right value and push back to stack.

//T
//?
//4
//:
//5

class Solution {
public:
    string parseTernary(string expression) {
        stack<char> st;
        int n = (int)expression.length();
        for (int idx = n - 1; idx >= 0; --idx) {
            char ch = expression[idx];
            if (!st.empty() && st.top() == '?') {
                st.pop(); // pop '?'
                char trch = st.top(); st.pop();
                st.pop(); // pop ':'
                char fch = st.top(); st.pop();
                if (ch == 'T') {
                    st.push(trch);
                } else {
                    st.push(fch);
                }
            } else {
                st.push(ch);
            }
        }
        // Trick.
        return string(1, st.top());
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

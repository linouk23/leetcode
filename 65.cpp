// 65. Valid Number - https://leetcode.com/problems/valid-number

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Trick: DFA (Deterministic Finite Automaton)

const string WS = " \t\n";
const string SIGNS = "+-";

class Solution {
public:
    bool isNumber(string s) {
        unordered_map<int, unordered_map<string, int> > dfa;
        // List of states,  dfa[i]
        // Init state (scan through whitespaces)
        dfa[1] = {{"ws", 1}, {"sign", 2}, {"digit", 3}, {".", 4}};
        // Sign was found, expect digit or dot to be the next char
        dfa[2] = {{"digit", 3}, {".", 4}};
        // Scan through digits
        dfa[3] = {{"digit", 3}, {".", 5}, {"e", 6}, {"ws", 9}};
        // Dot was found, expect a digit to be the next char
        dfa[4] = {{"digit", 5}};
        // After dot, expect a digit, e, or EOF to be the next char
        dfa[5] = {{"digit", 5}, {"e", 6}, {"ws", 9}};
        // "e" was found, expect a sign or a digit to be the next char
        dfa[6] = {{"sign", 7}, {"digit", 8}};
        // Sign after "e" was found, expect a digit to be the next char
        dfa[7] = {{"digit", 8}};
        // Digit (after "e") was found, expect a digit or EOF to be the next
        // char
        dfa[8] = {{"digit", 8}, {"ws", 9}};
        // Terminal state, expect whitespace to be the next char
        dfa[9] = {{"ws", 9}};
        
        int cur_state = 1;
        for (char ch : s) {
            string transition;
            if (isdigit(ch)) {
                transition = "digit";
            } else if (WS.find(ch) != string::npos) {
                transition = "ws";
            } else if (SIGNS.find(ch) != string::npos) {
                transition = "sign";
            } else if (dfa[cur_state].count(string(1, ch))) { // '.', 'e'
                transition = ch;
            }
            if (transition.empty() || !dfa[cur_state].count(transition)) {
                return false;
            }
            cur_state = dfa[cur_state][transition];
        }
        vector<int> term_states = {3, 5, 8, 9};
        return binary_search(term_states.begin(), term_states.end(), cur_state);
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_TRUE(sol.isNumber("0"));
    EXPECT_TRUE(sol.isNumber("1e3"));
    EXPECT_TRUE(sol.isNumber(" 0.333"));
    EXPECT_FALSE(sol.isNumber(" 0.33a3"));
    EXPECT_FALSE(sol.isNumber("1 d"));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

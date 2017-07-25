// 488. Zuma Game - https://leetcode.com/problems/zuma-game

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    const int INF = (int)1e9;
    unordered_map<string, unordered_map<string, int>> cache;
    // board -> hand -> result
    
    //unordered_map<string, string> rem;
    string rem_consec(const string &board) {
        for (int L = 0, R = 0; R < board.length(); ++R) {
            if (board[R] == board[L]) { continue; }
            // s[L] != s[R]
            if (R - L >= 3) {
                return rem_consec(board.substr(0, L) + board.substr(R));
            } else {
                L = R;
            }
        }
        return board;
    }
    int rec(string board, unordered_map<char, int> count) {
        board = rem_consec(board);
        if (board == "$") { return 0; }
        
        int result = INF;
        // Trick:
        // Remove any consec seq immediately.
        for (int L = 0, R = 0 ; R < board.length(); ++R) {
            if (board[L] == board[R]) { continue; }
            char cur_ball = board[L];
            // board[L] != board[R]
            // [L, R)
            if (R - L >= 3 && count[cur_ball] > 0) {
                // throw G into AGGGGD ->
                // result = 1 + result(AD)
                count[cur_ball] -= 1; // pop_back()
                result = min(result, 1 + rec(board.substr(0, L) +
                                             board.substr(R), count));
                count[cur_ball] += 1; // push_back()
            } else if (R - L < 3 && count[cur_ball] >= 3 - (R - L)) {
                // throw GG into AGD ->
                // result = 2 + result(AD)
                count[cur_ball] -= 3 - (R - L); // pop_back()
                result = min(result, 3 - (R - L) + rec(board.substr(0, L) +
                                                       board.substr(R), count));
                count[cur_ball] += 3 - (R - L); // push_back()
            }
            L = R;
        }
        return result;
    }
public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> count;
        for (char ch : hand) {
            count[ch] += 1;
        }
        // Use '$' instead of additional if
        // statement after for loop in rec()
        int result = rec(board + "$", count);
        return result == INF ? -1 : result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(-1, sol.findMinStep("WRRBBW", "RB"));
    EXPECT_EQ(2, sol.findMinStep("WWRRBBWW", "WRBRW"));
    EXPECT_EQ(2, sol.findMinStep("G", "GGGGG"));
    EXPECT_EQ(3, sol.findMinStep("RBYYBBRRB", "YRBGB"));
    EXPECT_EQ(2, sol.findMinStep("RRWWRRBBRR", "WB"));
    EXPECT_EQ(2, sol.findMinStep("WRYYRWWRRWW", "WYBR"));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

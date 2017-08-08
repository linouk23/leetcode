// 351. Android Unlock Patterns - https://leetcode.com/problems/android-unlock-patterns

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

//Each pattern must connect at least m keys and at most n keys.
//All the keys must be distinct.
//If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
//The order of keys used matters.
//| 1 | 2 | 3 |
//| 4 | 5 | 6 |
//| 7 | 8 | 9 |

class Solution {
private:
//    FRIEND_TEST(SolutionPrivateTest, DFS);
    int n, m;
    const int NUM_OF_DIGITS = 9;
    // from - to -> middle_element
    // (the one that should be visited already)
    unordered_map<int, unordered_map<int, int>> jump;
    int helper(deque<bool> visited, int cur_digit, int count) {
        visited[cur_digit] = true;
        int result = 0;
        if (count > n) { return 0; }
        if (count >= m && count <= n) {
            ++result;
        }
        
        for (int next_digit = 1; next_digit <= NUM_OF_DIGITS; ++next_digit) {
            if (visited[next_digit]) { continue; }
            // If 1->3, and 2 hasn't been visited yet.
            if (!visited[jump[cur_digit][next_digit]]) { continue; }
            result += helper(visited, next_digit, count + 1);
        }
        
        return result;
    }
public:
    int numberOfPatterns(int m, int n) {
        this->m = m, this->n = n;
        
        jump[1][3] = jump[3][1] = 2;
        jump[1][7] = jump[7][1] = 4;
        jump[3][9] = jump[9][3] = 6;
        jump[7][9] = jump[9][7] = 8;
        jump[1][9] = jump[9][1] = jump[2][8] = 5;
        jump[8][2] = jump[3][7] = jump[7][3] = 5;
        jump[4][6] = jump[6][4] = 5;
        
        int result = 0;
        deque<bool> visited(NUM_OF_DIGITS + 1, false);
        visited[0] = true;
        // The optimization idea is that 1,3,7,9 are symmetric, 
        // 2,4,6,8 are also symmetric. Hence we only calculate one among each group 
        // and multiply by 4.
        result += 4 * helper(visited, 1, 1); // 1, 3, 7, 9
        result += 4 * helper(visited, 2, 1); // 2, 4, 6, 8
        result += helper(visited, 5, 1); // 5
        return result;
    }
};

//TEST(SolutionPrivateTest, DFS) {
//    Solution sol;
//    EXPECT_EQ(9, sol.numberOfPatterns(1, 1));
//}

TEST(SolutionPublicTest, Small) {
    Solution sol;
    EXPECT_EQ(9, sol.numberOfPatterns(1, 1));
    EXPECT_EQ(56, sol.numberOfPatterns(2, 2));
    EXPECT_EQ(9096, sol.numberOfPatterns(3, 5));
}

TEST(SolutionPublicTest, Large) {
    Solution sol;
    EXPECT_EQ(389432, sol.numberOfPatterns(3, 10));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

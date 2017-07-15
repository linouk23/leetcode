// 533. Lonely Pixel II - https://leetcode.com/problems/lonely-pixel-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    string process_row(int row, vector<int>& col_count,
                       vector<vector<char>>& picture, int N) {
        string key = "";
        int row_count = 0;
        for (int col = 0; col < (int)picture[0].size(); ++col) {
            key += picture[row][col];
            if (picture[row][col] == 'B') {
                col_count[col] += 1;
                ++row_count;
            }
        }
        return (row_count == N) ? key : "";
    }
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int n = (int)picture.size();
        if (n == 0) return 0;
        int m = (int)picture[0].size();
        if (m == 0) return 0;
        
        vector<int> col_count(m, 0);
        // row -> count
        unordered_map<string, int> hashtable;
        for (int row = 0; row < n; ++row) {
            auto row_str = process_row(row, col_count, picture, N);
            if (row_str.empty()) { continue; }
            hashtable[row_str] += 1;
        }
        int result = 0;
        for (const auto &p : hashtable) {
            if (p.second != N) { continue; }
            for (int idx = 0; idx < m; ++idx) {
                if (p.first[idx] == 'B' && col_count[idx] == N) {
                    result += N;
                }
            }
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    vector<vector<char>> input = {
        {'W', 'B', 'W', 'B', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'B', 'W'},
        {'W', 'W', 'B', 'W', 'B', 'B'},
    };
    EXPECT_EQ(6, sol.findBlackPixel(input, 3));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// 79. Word Search - https://leetcode.com/problems/word-search

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool dfs(int row, int column, int index) {
        auto is_valid_pair = [this, &index](int row, int column) -> bool {
            return row >= 0 && column >= 0 &&
                   row < n  && column < m &&
                   board_[row][column] == word_[index];
        };
        if (!is_valid_pair(row, column)) { return false; }
        if (index == word_.length() - 1)  { return true; }
        char ch = board_[row][column];
        board_[row][column] = visited;
        
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, 1, -1, 0};
        for (int dir = 0; dir < 4; ++dir) {
            int new_row = row + dy[dir];
            int new_column = column + dx[dir];
            if (dfs(new_row, new_column, index + 1)) {
                return true;
            }
        }
        // Like pop_back()
        board_[row][column] = ch;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        board_ = board;
        n = (int)board.size();
        m = (int)board[0].size();
        word_ = word;
        bool result = false;
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < m; ++column) {
                result = result || dfs(row, column, 0);
                if (result) { return true; }
            }
        }
        return false;
    }
private:
    vector<vector<char> > board_;
    int n, m;
    char visited = '#';
    string word_;
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

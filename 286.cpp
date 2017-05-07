//  286. Walls and Gates - https://leetcode.com/problems/walls-and-gates

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = (int)rooms.size();
        int m = (int)rooms[0].size();
        const int INF = 2147483647;
        auto is_valid_cell = [&n, &m, &rooms](int row, int column) -> bool {
            return row >= 0 && row < n && column >= 0 && column < m &&
                   rooms[row][column] == INF;
        };
        queue<pair<int, int>> q;
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < m; ++column) {
                if (rooms[row][column] == 0) {
                    q.push({row, column});
                }
            }
        }
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            vector<int> dx = {0, 0, 1, -1};
            vector<int> dy = {-1, 1, 0, 0};
            for (int step = 0; step < 4; ++step) {
                pair<int, int> neighbour = {cur.first + dy[step],
                                            cur.second + dx[step]};
                if (is_valid_cell(neighbour.first, neighbour.second)) {
                    rooms[neighbour.first][neighbour.second] = rooms[cur.first][cur.second] + 1;
                    q.push(neighbour);
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

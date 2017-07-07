// 576. Out of Boundary Paths - https://leetcode.com/problems/out-of-boundary-paths

#include "bits/stdc++.h"

using namespace std;

struct Cell {
    int row, col, step;
    bool operator==(const Cell& that) const {
        return row == that.row && col == that.col &&
               step == that.step;
    }
};

namespace std {
    template <>
    struct hash<Cell> {
        size_t operator () (const Cell &o) const {
            unsigned long long value = (o.row << 16) | (o.col << 8) | o.step;
            return std::hash<unsigned long long>()(value);
        }
    };
}

struct Dir {
    int diff_row, diff_col;
};

class Solution {
private:
    unordered_map<Cell, long long> dp;
    unordered_set<Cell> visited;
    vector<Dir> dirs = {
        {-1, 0},
        {0,  1},
        {0, -1},
        {1,  0},
    };
    const long long mod = (long long)1e9 + 7;
    void add(long long &a, long long &b) {
        a = (a % mod + b % mod) % mod;
    }
public:
    int findPaths(int n, int m, int N, int row, int col) {
        
        auto is_valid = [n, m, N](const Cell &cell) -> bool {
            return cell.row >= 0 && cell.col >= 0 &&
                   cell.row < n && cell.col < m;
        };
        
        Cell start = { row, col, 0 };
        dp[start] = 1;
        visited.insert(start);
        queue<Cell> q;
        q.push(start);
        long long result = 0;
        while (!q.empty()) {
            Cell cell = q.front(); q.pop();
            if (cell.step == N) { continue; }
            for (const auto &dir : dirs) {
                Cell next_step = { cell.row + dir.diff_row,
                                   cell.col + dir.diff_col,
                                   cell.step + 1 };
                if (is_valid(next_step)) {
                    add(dp[next_step], dp[cell]);
                    // 1 | 2 | 3 -> we want to visit #2 from q only once,
                    // and we're good to add values from #1 and #3 to #2.
                    if (visited.count(next_step)) { continue; }
                    visited.insert(next_step);
                    q.push(next_step);
                } else {
                    add(result, dp[cell]);
                }
            }
        }
        return (int)result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

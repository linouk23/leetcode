// 542. 01 Matrix - https://leetcode.com/problems/01-matrix

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        n = (int)matrix.size();
        m = (int)matrix[0].size();
        vector<vector<int> > result(n, vector<int> (m));
        queue<Cell> q;
        set<Cell> visited;
        map<Cell, int> dist;
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < m; ++column) {
                if (matrix[row][column] == 1) { continue; }
                result[row][column] = 0;
                Cell cell(row, column);
                dist[cell] = 0;
                visited.insert(cell);
                q.push(cell);
            }
        }
        auto is_valid_cell = [this, &matrix](const Cell &cell) -> bool {
            return cell.row >= 0 && cell.row < n &&
                   cell.column >= 0 && cell.column < m &&
                   matrix[cell.row][cell.column] == 1;
        };
        
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            vector<int> dx = {-1, 0, 0, 1};
            vector<int> dy = {0, 1, -1, 0};
            for (int step = 0; step < 4; ++step) {
                int new_row = cur.row + dy[step];
                int new_column = cur.column + dx[step];
                Cell neighbour(new_row, new_column);
                if (!is_valid_cell(neighbour)) { continue; }
                if (visited.count(neighbour)) { continue; }
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[cur] + 1;
            }
        }
        for (int row = 0; row < n; ++row) {
            for (int column = 0; column < m; ++column) {
                if (matrix[row][column] == 0) { continue; }
                result[row][column] = dist[Cell(row, column)];
            }
        }
        return result;
    }
private:
    int n, m;
    struct Cell {
        int row, column;
        Cell() {}
        Cell(int row, int column) : row(row), column(column) {}
        bool operator <(const Cell& op) const {
            if (row != op.row)
                return row < op.row;
            return column < op.column;
        }
        
        bool operator ==(const Cell& op) const {
            return (row == op.row) && (column == op.column);
        }
    };
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

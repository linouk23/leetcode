// 305. Number of Islands II - https://leetcode.com/problems/number-of-islands-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class DSU {
private:
    vector<int> size, parent;
public:
    DSU(int num_of_vertices) {
        size.resize(num_of_vertices, 1);
        parent.resize(num_of_vertices);
        iota(parent.begin(), parent.end(), 0);
    }
    int get_size(int v) const {
        return size[v];
    }
    int find_set(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    // int find_set(int v) {
    //     while(v != parent[v]) {
    //         parent[v] = parent[parent[v]];   // only one line added
    //         v = parent[v];
    //     }
    //     return v;
    // }
    void merge(int v1, int v2) {
        int r1 = find_set(v1);
        int r2 = find_set(v2);
        if (r1 == r2) { return; }
        if (size[r1] > size[r2]) { swap(r1, r2); }
        // size[r1] <= size[r2]
        parent[r1] = r2;
        size[r2] += size[r1];
    }
};

class Solution {
private:
    struct Dir {
        int row_diff, col_diff;
    };
    vector<Dir> dirs = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
    };
    struct Cell {
        int size, parent;
    };
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>> positions) {
        unordered_set<int> ones;
        auto is_valid = [&ones, m, n](int row, int col) -> bool {
            return row >= 0 && col >= 0 && row < m && col < n &&
                   ones.count(row * m + col);
        };
        DSU dsu(m * n);
        vector<int> result;
        int count = 0;
        for (const auto &pos : positions) {
            int row, col;
            tie(row, col) = pos;
            int id = row * m + col;
            ones.insert(id);
            bool isSeparate = true;
            for (const auto dir : dirs) {
                int nrow = row + dir.row_diff;
                int ncol = col + dir.col_diff;
                if (!is_valid(nrow, ncol)) { continue; }
                int nid = nrow * m + ncol;
                dsu.merge(id, nid);
                isSeparate = false;
            }
            if (isSeparate) {
                count += 1;
            }
            result.emplace_back(count);
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    vector<int> expected = {1,1,2,3};
    EXPECT_EQ(expected, sol.numIslands2(3, 3,
                                         {{0,0}, {0,1}, {1,2}, {2,1}}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

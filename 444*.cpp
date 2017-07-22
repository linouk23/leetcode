// 444. Sequence Reconstruction - https://leetcode.com/problems/sequence-reconstruction

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// A digraph has a unique topological ordering if and only if
// there is a directed edge between each pair of consecutive
// vertices in the topological order (i.e., the digraph has a Hamiltonian path).
class Solution {
private:
    unordered_map<int, unordered_set<int>> g;
    unordered_set<int> visited;
    int N;
    vector<int> result;
    void dfs(int v) {
        visited.insert(v);
        for (int neighbour : g[v]) {
            if (visited.count(neighbour)) { continue; }
            dfs(neighbour);
        }
        result.emplace_back(v);
    }
    void run_top_sort() {
        result.clear();
        for (int v = 1; v <= N; ++v) {
            if (visited.count(v)) { continue; }
            dfs(v);
        }
        reverse(result.begin(), result.end());
    }
    bool check_result() {
        for (int idx = 0; idx < N - 1; ++idx) {
            int from = result[idx];
            int to = result[idx + 1];
            if (!g[from].count(to)) { return false; }
        }
        return true;
    }
public:
    bool sequenceReconstruction(vector<int> org, vector<vector<int>> seqs) {
        N = INT_MIN;
        for (const auto &sec : seqs) {
            int n = (int)sec.size();
            N = max(N, *max_element(sec.begin(), sec.end()));
            for (int idx = 0; idx < n - 1; ++idx) {
                int from = sec[idx];
                int to = sec[idx + 1];
                g[from].insert(to);
            }
        }
        run_top_sort();
        bool isUnique = check_result();
        if (!isUnique) { return false; }
        return result == org;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_TRUE(sol.sequenceReconstruction({4,1,5,2,6,3},
                                           {{5,2,6,3},{4,1,5,2}}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

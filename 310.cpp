// 310. Minimum Height Trees - https://leetcode.com/problems/minimum-height-trees

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> edges) {
        if (edges.empty()) {
            vector<int> result(n);
            iota(result.begin(), result.end(), 0);
            return result;
        }
        unordered_map<int, vector<int>> g;
        int from, to;
        for (const auto &edge : edges) {
            tie(from, to) = edge;
            g[from].emplace_back(to);
            g[to].emplace_back(from);
        }
        
        queue<int> q;
        vector<bool> visited(n, false);
        vector<int> prev(n, -1), dist(n, 0);
        int start = 0;
        visited[start] = true;
        q.push(start);
        int next_start = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            next_start = v;
            for (int neighbour : g[v]) {
                if (visited[neighbour]) { continue; }
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
        visited.assign(n, false);
        visited[next_start] = true;
        dist[next_start] = 0;
        q.push(next_start);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int neighbour : g[v]) {
                if (visited[neighbour]) { continue; }
                visited[neighbour] = true;
                prev[neighbour] = v;
                dist[neighbour] = dist[v] + 1;
                q.push(neighbour);
            }
        }
        int finish = int(max_element(dist.begin(), dist.end()) - dist.begin());
        vector<int> path, result;
        while (finish != -1) {
            path.emplace_back(finish);
            finish = prev[finish];
        }
        int len = (int)path.size();
        if (len % 2 == 0) {
            result = {path[len / 2], path[len / 2 - 1]};
        } else {
            result = {path[len / 2]};
        }
        return result;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

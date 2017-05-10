// 210. Course Schedule II - https://leetcode.com/problems/course-schedule-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void createGraph(vector<pair<int, int>>& prerequisites) {
        g.resize(n);
        int from, to;
        for (const auto &p : prerequisites) {
            tie(from, to) = p;
            g[from].push_back(to);
        }
    }
    
    void topSort() {
        is_visited.assign(n, false);
        for (int vertex = 0; vertex < n; ++vertex) {
            if (is_visited[vertex]) { continue; }
            dfs(vertex);
        }
    }
    
    void dfs(int vertex) {
        is_visited[vertex] = true;
        for (int neighbour : g[vertex]) {
            if (!is_visited[neighbour]) {
                dfs(neighbour);
            }
        }
        result.emplace_back(vertex);
    }
    
    bool dfs2(int vertex) {
        color[vertex] = 1;
        for (int neighbour : g[vertex]) {
            if (color[neighbour] == 1) {
                return true;
            } else if (color[neighbour]) {
                if (dfs2(neighbour)) {
                    return true;
                }
            }
        }
        color[vertex] = 2;
        return false;
    }
    
    bool hasCycle() {
        is_visited.resize(n, false);
        color.resize(n, 0);
        for (int vertex = 0; vertex < n; ++vertex) {
            if (color[vertex] == 2) { continue; }
            if (dfs2(vertex)) {
                return true;
            }
        }
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>> prerequisites) {
        n = numCourses;
        createGraph(prerequisites);
        if (!hasCycle()) {
            topSort();
            return result;
        }
        return {};
    }
private:
    vector<vector<int> > g;
    int n;
    vector<int> result, color;
    vector<bool> is_visited;
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 582. Kill Process - https://leetcode.com/problems/kill-process

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int> pid, vector<int> ppid, int kill) {
        unordered_map<int, vector<int>> g;
        int n = (int)pid.size();
        for (int idx = 0; idx < n; ++idx) {
            int from = ppid[idx];
            int to = pid[idx];
            g[from].emplace_back(to);
        }
        vector<int> result;
        int start = kill;
        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);
        while(!q.empty()) {
            int vertex = q.front(); q.pop();
            result.emplace_back(vertex);
            for (int neighbour : g[vertex]) {
                if (visited.count(neighbour)) { continue; }
                visited.insert(neighbour);
                q.push(neighbour);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

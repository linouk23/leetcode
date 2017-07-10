// 399. Evaluate Division - https://leetcode.com/problems/evaluate-division

#include "bits/stdc++.h"

using namespace std;

// a/b = k => a -> (k) -> b, b -> (1/k) -> a
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        // to -> from -> weight
        unordered_map<string, unordered_map<string, double> > g;
        for (int idx = 0; idx < (int)equations.size(); ++idx) {
            auto from = equations[idx].first;
            auto to = equations[idx].second;
            double weight = values[idx];
            g[from][to] = weight;
            g[to][from] = 1 / weight;
        }
        
        vector<double> result;
        for (const auto &query : queries) {
            auto from = query.first;
            if (!g.count(from)) {
                result.emplace_back(-1);
                continue;
            }
            auto to = query.second;
            unordered_map<string, bool> visited;
            unordered_map<string, string> prev;
            visited[from] = true;
            prev[from] = from;
            queue<string> q;
            q.push(from);
            while(!q.empty()) {
                auto vertex = q.front(); q.pop();
                for (const auto & edge : g[vertex]) {
                    string neighbour = edge.first;
                    if (visited[neighbour]) { continue; }
                    visited[neighbour] = true;
                    prev[neighbour] = vertex;
                    q.push(neighbour);
                }
            }
            if (!visited[to]) {
                result.emplace_back(-1);
                continue;
            }
            double total_weight = 1.0;
            string vertex = to;
            while (prev[vertex] != vertex) {
                total_weight *= g[prev[vertex]][vertex];
                vertex = prev[vertex];
            }
            result.emplace_back(total_weight);
            g[from][to] = total_weight;
            g[to][from] = 1 / total_weight;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

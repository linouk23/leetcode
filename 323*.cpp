// 323. Number of Connected Components in an Undirected Graph - https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph

#include "bits/stdc++.h"

using namespace std;

// class Solution {
// public:
//     int countComponents(int n, vector<pair<int, int>>& edges) {
//         vector<int> p(n);
//         iota(begin(p), end(p), 0);
//         function<int (int)> find = [&](int v) {
//             return p[v] == v ? v : p[v] = find(p[v]);
//         };
//         for (auto& edge : edges) {
//             int v = find(edge.first), w = find(edge.second);
//             p[v] = w;
//             n -= v != w;
//         }
//         return n;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

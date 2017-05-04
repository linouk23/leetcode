// 261. Graph Valid Tree - https://leetcode.com/problems/graph-valid-tree

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void disjoint_set_union_init() {
        parent.resize(n_);
        size.resize(n_);
        for (int vertex = 0; vertex < n_; ++vertex) {
            parent[vertex] = vertex;
            size[vertex] = 1;
        }
    }
    
    int disjoint_set_union_find_set(int vertex) {
        if (parent[vertex] == vertex) {
            return vertex;
        }
        return parent[vertex] = disjoint_set_union_find_set(parent[vertex]);
    }
    
    bool disjoint_set_union_merge(int fst_v, int snd_v) {
        int fst_set = disjoint_set_union_find_set(fst_v);
        int snd_set = disjoint_set_union_find_set(snd_v);
        if (fst_set == snd_set) { return false; }
        if (size[fst_set] > size[snd_set]) {
            swap(fst_set, snd_set);
        }
        parent[fst_set] = snd_set;
        size[snd_set] += size[fst_set];
        return true;
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        // To tell whether a graph is a valid tree, we have to:
        // 1. Make sure there is no cycle in the graph - this has to be a none-cyclic graph;
        // 2. Make sure every node is reached - this has to be a connected graph.
        n_ = n;
        edges_ = edges;
        disjoint_set_union_init();
        for (const auto & edge : edges) {
            if (!disjoint_set_union_merge(edge.first, edge.second)) {
                return false;
            }
        }
        return edges.size() == n - 1;
    }
private:
    int n_;
    vector<int> parent, size;
    vector<pair<int, int>> edges_;
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

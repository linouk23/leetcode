// 565. Array Nesting - https://leetcode.com/problems/array-nesting

#include "bits/stdc++.h"

using namespace std;

// Trick.
// Each element of array A is an integer within the range [0, N-1].
// Successor graphs. In those graphs, the outdegree of each node
// is 1, i.e., exactly one edge starts at each node.
// A successor graph consists of one or more components,
// each of which contains one cycle and some paths that
// lead to it. Successor graphs are sometimes called
// functional graphs. The reason for this is that any
// successor graph corresponds to a function that defines the edges
// of the graph. The parameter for the function is a node
// of the graph, and the function gives the successor of that node.

class Solution {
private:
    vector<bool> visited;
    vector<int> comp;
    int result;
    vector<int> f(int x, vector<int>& nums) {
        return {nums[x]};
    }
    void dfs(int vertex, vector<int>& nums) {
        visited[vertex] = true;
        comp.emplace_back(vertex);
        for (int neighbour : f(vertex, nums)) {
            if (visited[neighbour]) { continue; }
            dfs(neighbour, nums);
        }
    }
public:
    int arrayNesting(vector<int>& nums) {
        int n = (int)nums.size();
        visited.resize(n, false);
        result = INT_MIN;
        for (int vertex = 0; vertex < n; ++vertex) {
            if (visited[vertex]) { continue; }
            comp.clear();
            dfs(vertex, nums);
            result = max((int)comp.size(), result);
        }
        return result;
    }
};



int main() {
    ios::sync_with_stdio(false);
    return 0;
}

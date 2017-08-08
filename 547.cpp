// 547. Friend Circles - https://leetcode.com/problems/friend-circles

#include "bits/stdc++.h"

using namespace std;
    
class Solution {
private:
    int n;
    void dfs(int node, deque<bool> &visited, vector<vector<int>>& M) {
        visited[node] = true;
        for (int neighbour = 0; neighbour < n; ++neighbour) {
            if (M[node][neighbour] == 0) { continue; }
            if (visited[neighbour]) { continue; }
            dfs(neighbour, visited, M);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        n = (int)M.size();
        deque<bool> visited(n, false);
        int result = 0;
        for (int node = 0; node < n; ++node) {
            if (visited[node]) { continue; }
            dfs(node, visited, M);
            ++result;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

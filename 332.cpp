// 332. Reconstruct Itinerary - https://leetcode.com/problems/reconstruct-itinerary

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// http://e-maxx.ru/algo/euler_path
class Solution {
private:
    unordered_map<string, multiset<string>> g;
    vector<string> path;
    void dfs(const string & airport) {
        while (!g[airport].empty()) {
            string neighbour = *g[airport].begin();
            // vs .erase(neighbour)
            g[airport].erase(g[airport].begin());
            dfs(neighbour);
        }
        path.emplace_back(airport);
    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        string from, to;
        for (const auto & ticket : tickets) {
            tie(from, to) = ticket;
            g[from].insert(to);
        }
        string start = "JFK";
        dfs(start);
        reverse(path.begin(), path.end());
        return path;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

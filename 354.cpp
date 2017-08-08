// 354. Russian Doll Envelopes - https://leetcode.com/problems/russian-doll-envelopes

#include "bits/stdc++.h"

using namespace std;

//inline bool fits(pair<int, int> &small, pair<int, int> &big) {
//    return small.first < big.first && small.second < big.second;
//}
//
//class Solution {
//private:
//    int n;
//    vector<vector<int>> g;
//    deque<bool> visited;
//    vector<int> top_sort_result;
//    
//    void create_graph(vector<pair<int, int>>& envelopes) {
//        g.resize(n);
//        for (int from = 0; from < n; ++from) {
//            for (int to = from + 1; to < n; ++to) {
//                if (fits(envelopes[from], envelopes[to])) {
//                    g[from].emplace_back(to);
//                } else if (fits(envelopes[to], envelopes[from])) {
//                    g[to].emplace_back(from);
//                }
//            }
//        }
//    }
//    
//    void dfs(int v) {
//        visited[v] = true;
//        for (auto neighbour : g[v]) {
//            if (!visited[neighbour]) {
//                dfs(neighbour);
//            }
//        }
//        top_sort_result.emplace_back(v);
//    }
//    
//    vector<int> run_top_sort() {
//        visited.resize(n, false);
//        for (int v = 0; v < n; ++v) {
//            if (!visited[v]) {
//                dfs(v);
//            }
//        }
//        reverse(top_sort_result.begin(), top_sort_result.end());
//        return top_sort_result;
//    }
//    
//    int find_max_path_in_dag(vector<int> &order) {
//        // Max vertices path.
//        vector<int> len(n, 1);
//        for (int second_last : order) {
//            for (int last : g[second_last]) {
//                len[last] = max(len[last], len[second_last] + 1);
//            }
//        }
//        return *max_element(len.begin(), len.end());
//    }
//public:
//    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
//        if (envelopes.empty()) { return 0; }
//        n = (int)envelopes.size();
//        create_graph(envelopes);
//        auto order = run_top_sort();
//        return find_max_path_in_dag(order);
//    }
//};

struct Doll {
    int width, height;
    bool operator<(const Doll & that) const {
        // Trick.
        // Ascend on width and descend on height if width are same.
        // Since the width is increasing, we only need to consider height.
        // [3, 4] cannot contains [3, 3], so we need to put [3, 4]
        // before [3, 3] when sorting otherwise it will be counted
        // as an increasing number if the order is [3, 3], [3, 4]
        if (width == that.width) { return height > that.height; }
        return width < that.width;
    }
};

// Trick.
// 1. Sort the array. Ascend on width and descend on height if width are same.
// 2. Find the longest increasing subsequence based on height.
class Solution {
private:
    vector<Doll> dolls;
    int n;
    int get_pos(const Doll &doll, vector<Doll> &dp) {
        // dp      = -inf 2 4 5 +inf ...
        // f(dp, 3)=   0  0 1 1  1 -> (L, R) -> R = idx(4)
        // f(dp, 4)=   0  0 1 1  1 -> (L, R) -> R = idx(4)
        // obj > dp[i] -> 0
        // obj <= dp[i] -> 1
        int L = 0 - 1, R = n + 1;
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (!(dp[M].height < doll.height)) {
                R = M;
            } else {
                L = M;
            }
        }
        return R;
    }
public:
    int maxEnvelopes(vector<pair<int, int>>envelopes) {
        // if (envelopes.empty()) { return 0; }
        for (const auto &p : envelopes) {
            dolls.push_back({p.first, p.second});
        }
        sort(dolls.begin(), dolls.end());
        n = (int)dolls.size();
        // Let dp[i] be the last min doll for increasing sequence of length i (0...n).
        // Answer: max_n : dp[n] != INT_MAX.
        vector<Doll> dp(n + 1, {INT_MAX, INT_MAX});
        dp[0] = {INT_MIN, INT_MIN};
        for (const Doll &doll : dolls) {
            int pos = get_pos(doll, dp);
            dp[pos] = doll;
        }
        return get_pos({INT_MAX, INT_MAX}, dp) - 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

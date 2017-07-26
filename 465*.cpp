// 465. Optimal Account Balancing - https://leetcode.com/problems/optimal-account-balancing

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    const int INF = (int)1e9;
private:
    int helper(vector<int> v, int start, int n, int res_so_far) {
        int result = INF;
        while (start < n && v[start] == 0) { start += 1; }
        for (int idx = start + 1; idx < n; ++idx) {
            // Opposite sign.
            if ((v[idx] < 0 && v[start] > 0) || (v[idx] > 0 && v[start] < 0)) {
                v[idx] += v[start];
                result = min(result, helper(v, start + 1, n, res_so_far + 1));
                v[idx] -= v[start];
            }
        }
        return result == INF ? res_so_far : result;
    }
public:
    int minTransfers(vector<vector<int>> trans) {
        unordered_map<int, int> net;
        for (const auto &t : trans) {
            net[t[0]] -= t[2];
            net[t[1]] += t[2];
        }
        int n = (int)net.size();
        vector<int> v(n);
        int idx = 0;
        for (const auto &p : net) {
            if (p.second == 0) { continue; }
            v[idx++] = p.second;
        }
        return helper(v, 0, idx, 0);
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(2, sol.minTransfers({{0,1,10}, {2,0,5}}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

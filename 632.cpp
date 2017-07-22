// 632. Smallest Range - https://leetcode.com/problems/smallest-range

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Idea: merge k sorted arrays, keep track of min in the heap,
// max – manually.
// while (pq.size() == n) to keep every list in pq.
class Solution {
private:
    const int INF = (int)1e9;
    struct Triple {
        int val, val_idx, list_idx;
        bool operator>(const Triple &that) const {
            return val > that.val;
        }
    };
public:
    vector<int> smallestRange(vector<vector<int>> nums) {
        priority_queue<Triple, vector<Triple>,greater<Triple>> pq;
        int n = (int)nums.size();
        struct Result {
            int diff, min_val, max_val, L, R;
            void update(int root_val, int num) {
                min_val = root_val;
                max_val = max(max_val, num);
                if (diff > max_val - min_val) {
                    L = min_val;
                    R = max_val;
                    diff = R - L;
                }
            }
        } result { INF, INF };
        for (int idx = 0; idx < n; ++idx) {
            pq.push({nums[idx][0], 0, idx});
            result.update(pq.top().val, nums[idx][0]);
        }
        result.R = result.max_val;
        result.L = result.min_val;
        result.diff = result.R - result.L;
        // while (!pq.empty()) {
        // Trick:
        while (pq.size() == n) {
            auto t = pq.top(); pq.pop();
            if (t.val_idx + 1 == (int)nums[t.list_idx].size()) { continue; }
            int num = nums[t.list_idx][t.val_idx + 1];
            pq.push({ num, t.val_idx + 1, t.list_idx });
            result.update(pq.top().val, num);
        }
        return {result.L, result.R};
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

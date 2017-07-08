// 228. Summary Ranges - https://leetcode.com/problems/summary-ranges

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) { return {}; }
        int n = (int)nums.size();
        int idxL = 0;
        int idxR = 0;
        vector<pair<int, int>> res_pairs;
        for (int idx = 1; idx < n; ++idx) {
            if (nums[idx] == nums[idxL] + idx - idxL) {
                idxR = idx;
            } else {
                res_pairs.push_back({idxL, idxR});
                idxL = idx;
                idxR = idx;
            }
        }
        res_pairs.push_back({idxL, idxR});
        vector<string> result;
        for (const auto &p : res_pairs) {
            if (p.first == p.second) {
                result.push_back(to_string(nums[p.first]));
            } else {
                result.push_back(to_string(nums[p.first]) + "->" +
                                 to_string(nums[p.second]));
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

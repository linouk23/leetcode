// 624. Maximum Distance in Arrays - https://leetcode.com/problems/maximum-distance-in-arrays

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        if (arrays.empty()) { return 0; }
        int max_diff = 0, min_val = arrays[0].front();
        int max_val = arrays[0].back();
        for (int idx = 1; idx < (int)arrays.size(); ++idx) {
            auto arr = arrays[idx];
            // Trick to avoid use max, min from the same row.
            max_diff = max(max_diff, max(arr.back() - min_val,
                                         max_val - arr.front()));
            min_val = min(min_val, arr.front());
            max_val = max(max_val, arr.back());
        }
        return max_diff;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

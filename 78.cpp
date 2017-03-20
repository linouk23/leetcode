// 78. Subsets - https://leetcode.com/problems/subsets

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> result;
        for (int subset = 0; subset < (1 << n); ++subset) {
            vector<int> sset;
            for (int index = 0; index < n; ++index) {
                if (subset & (1 << index)) {
                    sset.emplace_back(nums[index]);
                }
            }
            result.push_back(sset);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

// 39. Combination Sum - https://leetcode.com/problems/combination-sum

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    vector<vector<int> > result;
    vector<int> nums;
    int n;
    void helper(int target, int index, vector<int> cur_vec) {
        // Either take it or not
        if (target < 0) { return; }
        if (target == 0) {
            result.emplace_back(cur_vec);
            return;
        }
        if (index == n) { return; }
        
        // Take cur element k times
        int upper_bound_it = target / nums[index];
        for (int k = 1; k <= upper_bound_it; ++k) {
            cur_vec.emplace_back(nums[index]);
            helper(target - k * nums[index], index + 1, cur_vec);
        }
        cur_vec.erase(cur_vec.end() - upper_bound_it, cur_vec.end());
        
        // Leave out cur element
        helper(target, index + 1, cur_vec);
    }
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        nums = candidates;
        n = (int)candidates.size();
        helper(target, 0, {});
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

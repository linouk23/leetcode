// 40. Combination Sum II - https://leetcode.com/problems/combination-sum-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    set<vector<int> > result;
    vector<int> nums;
    int n;
    void helper(int target, int index, vector<int> cur_vec) {
        // Either take it or not
        if (target < 0) { return; }
        if (target == 0) {
            result.insert(cur_vec);
            return;
        }
        if (index == n) { return; }
        
        // Take cur element
        cur_vec.emplace_back(nums[index]);
        helper(target - nums[index], index + 1, cur_vec);
        cur_vec.pop_back();
        
        // Leave out cur element
        helper(target, index + 1, cur_vec);
    }
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        nums = candidates;
        sort(nums.begin(), nums.end());
        n = (int)candidates.size();
        helper(target, 0, {});
        return {result.begin(), result.end()};
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

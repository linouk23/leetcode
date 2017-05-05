// 491. Increasing Subsequences - https://leetcode.com/problems/increasing-subsequences

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    set<vector<int> > result;
public:
    void helper(vector<int>& nums, int start, vector<int> cur) {
        if (start > (int)nums.size()) {
            return;
        }
        if ((int)cur.size() >= 2) {
            result.insert(cur);
        }
        for (int index = start; index < (int)nums.size(); ++index) {
            if (cur.empty() || cur.back() <= nums[index]) {
                cur.emplace_back(nums[index]);
                helper(nums, index + 1, cur);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        helper(nums, 0, {});
        return {result.begin(), result.end()};
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

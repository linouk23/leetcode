// 46. Permutations - https://leetcode.com/problems/permutations

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        // {6, 2, 1, 5, 4, 3, 0} -> {0, 3, 4, 5, 1, 2, 6} -> 1
        bool has_next_one = true;
        while(has_next_one) {
            result.emplace_back(nums);
            auto break_point = is_sorted_until(nums.rbegin(), nums.rend());
            bool has_next_one = !(break_point == nums.rend());
            if (!has_next_one) {
                break;
            }
            
            // {0, 3, 4, 5}, x > 1 -> 3
            auto least_upper_bound = upper_bound(nums.rbegin(), break_point, *break_point);
            
            // {6, 2, 1, 5, 4, 3, 0} -> {6, 2, 3, 5, 4, 1, 0}
            iter_swap(break_point, least_upper_bound);
            
            // Since the suffix is sorted, reverse == sort:
            // {6, 2, 3, 5, 4, 1, 0} -> {6, 2, 3, 0, 1, 4, 5}
            reverse(nums.rbegin(), break_point);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

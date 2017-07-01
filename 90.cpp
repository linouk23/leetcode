// 90. Subsets II - https://leetcode.com/problems/subsets-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        vector<vector<int> > result = {{}};
        for (int ind = 0; ind < n; ++ind) {
            int freq = 1;
            int num = nums[ind];
            while (ind < n && nums[ind] == nums[ind + 1]) { ++freq; ++ind; }
            auto prevSet = result;
            for (auto temp : prevSet) {
                for (int k = 0; k < freq; ++k) {
                    temp.emplace_back(num);
                    result.emplace_back(temp);
                }
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

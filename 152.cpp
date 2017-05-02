// 152. Maximum Product Subarray - https://leetcode.com/problems/maximum-product-subarray

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> maxs(n), mins(n);
        maxs[0] = mins[0] = nums[0];
        for (int index = 1; index < n; ++index) {
            maxs[index] = max({nums[index],
                              nums[index] * maxs[index - 1],
                              nums[index] * mins[index - 1]});
            mins[index] = min({nums[index],
                              nums[index] * maxs[index - 1],
                              nums[index] * mins[index - 1]});
        }
        
        int result = -1e9;
        for (int answer : maxs) {
            result = max(result, answer);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

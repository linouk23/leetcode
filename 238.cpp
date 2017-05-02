// 238. Product of Array Except Self - https://leetcode.com/problems/product-of-array-except-self

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        result[0] = 1;
        for (int index = 1; index < nums.size(); ++index) {
            result[index] = result[index - 1] * nums[index - 1];
        }
        int right_mult = 1;
        for (int index = (int)nums.size() - 1; index >= 0; --index) {
            result[index] *= right_mult;
            right_mult *= nums[index];
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

// 628. Maximum Product of Three Numbers - https://leetcode.com/problems/maximum-product-of-three-numbers

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        vector<int> results(2);
        results[0] = nums[n - 1] * nums[n - 2] * nums[n - 3];
        results[1] = nums[n - 1] * nums[0] * nums[1];
        return *max_element(results.begin(), results.end());
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

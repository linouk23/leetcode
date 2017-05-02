// 442. Find All Duplicates in an Array - https://leetcode.com/problems/find-all-duplicates-in-an-array

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> result;
        for (int index = 0; index < n; ++index) {
            int true_index = abs(nums[index]) - 1;
            if (nums[true_index] > 0) {
                nums[true_index] *= -1;
            } else {
                result.emplace_back(true_index + 1);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

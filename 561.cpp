// 561. Array Partition I - https://leetcode.com/problems/array-partition-i

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int index = 0; index < (int)nums.size(); index += 2) {
            result += nums[index];
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

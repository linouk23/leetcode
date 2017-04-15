// 75. Sort Colors - https://leetcode.com/problems/sort-colors

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int L = 0, M = 0;
        int R = (int)nums.size() - 1;
        
        while (M <= R) {
            if (nums[M] == 0) { swap(nums[L++], nums[M++]); }
            else if (nums[M] == 2) { swap(nums[M], nums[R--]); }
            else { ++M; }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

// 80. Remove Duplicates from Sorted Array II - https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        if (n < 2) {
            return n;
        }
        
        int index_to_write = 2;
        for (int index = 2; index < n; ++index) {
            if (nums[index] != nums[index_to_write - 2]) {
                nums[index_to_write++] = nums[index];
            }
        }
        return index_to_write;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

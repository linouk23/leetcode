// 154. Find Minimum in Rotated Sorted Array II - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int bin_search_pivot() {
        int L = 0 - 1;
        int R = (n - 1) + 1;
        int last_element = nums_[n - 1];
        // 0000111
        auto check = [&last_element](int middle_element) -> bool {
            return middle_element <= last_element;
        };
        
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (check(nums_[M])) {
                R = M;
            } else {
                L = M;
            }
        }
        return R;
    }
    
    int findMin(vector<int>& nums) {
        if (nums.empty()) { return -1; }
        nums_ = nums;
        n = (int)nums_.size();
        int start = 0;
        while (start + 1 < n - 1 && nums_[start] == nums_[n - 1]) {
            --n;
        }
        int pivot = bin_search_pivot();
        return nums_[pivot];
    }
private:
    vector<int> nums_;
    int n;
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

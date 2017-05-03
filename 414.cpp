// 414. Third Maximum Number - https://leetcode.com/problems/third-maximum-number

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        const int null_ = INT_MIN + 3;
        int max1 = null_;
        int max2 = null_;
        int max3 = null_;
        for (int num : nums) {
            if (num == max1 || num == max2 || num == max3) continue;
            if (max1 == null_ || num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (max2 == null_ || num > max2) {
                max3 = max2;
                max2 = num;
            } else if (max3 == null_ || num > max3) {
                max3 = num;
            }
        }
        return max3 == null_ ? max1 : max3;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

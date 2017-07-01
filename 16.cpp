// 16. 3Sum Closest - https://leetcode.com/problems/3sum-closest

#include "bits/stdc++.h"

using namespace std;

const int INF = (int)1e9;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        if (n <= 3) { return accumulate(nums.begin(), nums.end(), 0); }
        int cur_sum = accumulate(nums.begin(), nums.begin() + 3, 0);
        /* v[0] v[1] v[2] ... v[i] .... v[M] ... v[k] ... v[n-2] v[n-1]
         *                    v[i]  <=  v[M]  <= v[k] because we sorted our array.
         * Now, for each number, v[M] : we look for pairs v[L] & v[R] such that
         * absolute value of (target - (v[M] + v[L] + v[R]) is minimised.
         * if the sum of the triplet is greater then the target it implies
         * we need to reduce our sum, so we do --R, that is we reduce
         * our sum by taking a smaller number.
         * Simillarly if sum of the triplet is less then the target then we
         * increase out sum by taking a larger number, i.e. ++L.
         */
        int result = INF;
        for (int M = 1; M < n - 1; ++M) {
            cur_sum = INF;
            int L = 0;
            int R = n - 1;
            while (L < M && M < R) {
                cur_sum = nums[L] + nums[M] + nums[R];
                if (target > cur_sum) {
                    ++L;
                } else if (target == cur_sum) {
                    return target;
                } else {
                    --R;
                }
                if (abs(result - target) > (abs(cur_sum - target))) {
                    result = cur_sum;
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

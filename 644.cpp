// 644. Maximum Average Subarray II - https://leetcode.com/problems/maximum-average-subarray-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Trick: min_prefix to choose k
// (nums[i]+nums[i+1]+...+nums[j])/(j-i+1)>x
// nums[i]+nums[i+1]+...+nums[j]>x*(j-i+1)
// (nums[i]-x)+(nums[i+1]-x)+...+(nums[j]-x)>0
const double INF = 1e8;
class Solution {
private:
    bool check(vector<double> &nums, double M, int k) {
        for (double &num : nums) {
            num -= M;
        }
        int n = (int)nums.size();
        vector<double> prefix(n + 1), min_prefix(n + 1, INF);
        prefix[0] = min_prefix[0] = 0;
        for (int idx = 1; idx <= n; ++idx) {
            prefix[idx] = prefix[idx - 1] + nums[idx - 1];
            min_prefix[idx] = min(min_prefix[idx - 1], prefix[idx]);
        }
        for (double &num : nums) {
            num += M;
        }
        for (int idx = k; idx <= n; ++idx) {
            double sum = prefix[idx] - min_prefix[idx - k];
            if (sum > 0) { return true; }
        }
        return false;
    }
public:
    double findMaxAverage(vector<int> nums, int k) {
        vector<double> dnums(nums.begin(), nums.end());
        double L = -INF, R = INF;
        double diff = 7 * 1e-6;
        // 1 1 1 1 1 1 0 0 0 0 0 0
        while (R - L > diff) {
            double M = L + (R - L) / 2.0;
            if (check(dnums, M, k)) {
                L = M;
            } else {
                R = M;
            }
        }
        return L;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

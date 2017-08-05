// 327. Count of Range Sum - https://leetcode.com/problems/count-of-range-sum

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

typedef long long ll;

// Part:
// T[L, R] = T[L, M - 1] + T[M, R] + subproblem
// subproblem:
// num of pairs such that
// 1) prefix[R] - prefix[L] >= lower
// 2) prefix[R] - prefix[L] <= upper
// where L \in left part, R \in right part
// Result:
// T[0, n - 1]

class Solution {
private:
    int result;
    vector<ll> buffer;
    void mergeSortAndCount(vector<ll> &nums, int L, int R,
                           int lower, int upper) {
        if (L >= R) { return; }
        int M = L + (R - L) / 2;
        mergeSortAndCount(nums, L, M, lower, upper);
        mergeSortAndCount(nums, M + 1, R, lower, upper);
        merge(nums, L, M + 1, R, lower, upper);
    }
    void merge(vector<ll> &nums, int L, int M, int R,
               int lower, int upper) {
        // [L, M), [M, R]
        int bufLen = M - L;
        for (int idx = 0; idx < bufLen; ++idx) {
            buffer[idx] = nums[idx + L];
        }
        // Count
        // 1 3 7
        // -5 2 2 8
        // [2,4]
        // [>=2] - [>4] = [2, 4]
        // Instead of numbers -> idxs
        // Trick:
        // For each idx from left part,
        // we need to find two indices
        // fL and fU in the right half where
        // 1) fU is the first index satisfy sums[fU] - sums[i] > upper and
        // 2) fL is the first index satisfy sums[fL] - sums[i] >= lower.
        // Then the number of sums in [lower, upper] is fU - fL.
        int fL = M, fU = M;
        int P1 = 0;
        while (P1 < bufLen) {
            while (fL <= R && nums[fL] - buffer[P1] < lower) { ++fL; }
            while (fU <= R && nums[fU] - buffer[P1] <= upper) { ++fU; }
            result += fU - fL;
            P1 += 1;
        }
        
        // Merge
        int L1 = 0, L2 = M;
        int idxToWrite = L;
        while (L1 < bufLen && L2 <= R) {
            if (buffer[L1] < nums[L2]) {
                nums[idxToWrite++] = buffer[L1++];
            } else {
                nums[idxToWrite++] = nums[L2++];
            }
        }
        while (L1 < bufLen) {
            nums[idxToWrite++] = buffer[L1++];
        }
        while (L2 <= R) {
            nums[idxToWrite++] = nums[L2++];
        }
    }
public:
    int countRangeSum(vector<int> nums, int lower, int upper) {
        int n = (int)nums.size();
        result = 0;
        buffer.resize(n + 1);
        vector<ll> prefix(n + 1);
        for (int idx = 1; idx <= n; ++idx) {
            prefix[idx] = prefix[idx - 1] + 1LL * nums[idx - 1];
        }
        mergeSortAndCount(prefix, 0, n, lower, upper);
        return result;
    }
};

// Seq:
// T[L, R] = T[L, R - 1] + subproblem
// T[0, R] = T[0, R - 1] + subproblem
// subproblem:
// num of pairs such that
// 1) prefix[R] - prefix[i] >= lower
// 2) prefix[R] - prefix[i] <= upper
// where i \in [0, R - 1]
// Result:
// T[0, n - 1]
// TODO: segment tree

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(3, sol.countRangeSum({-2,5,-1}, -2, 2));
    EXPECT_EQ(3, sol.countRangeSum({0, 0}, 0, 0));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

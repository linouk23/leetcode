// 363. Max Sum of Rectangle No Larger Than K - https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Trick: submatrix -> contiguous subarray of rows -> Kadane 1D + 2 pointers
// Instead of Kadane -> prefix sums in place using set.

// Same as max submatrix:
// Move [L, R] (L <= R, 2 pointers for cols) as a left and right
// borders of submatrix -> calculate 1 col -> total sum for this submatrix
// -> run Kadane 1d (dp[i] - max sum ending at arr[i],
// *max_element(dp.begin(), dp.end())
// maximum subarray problem is the task of finding the contiguous
// subarray within a one-dimensional array of numbers which has the largest sum.

/*
class Solution {
private:
    const int INF = (int)1e9;
public:
    int maxSumSubmatrix(vector<vector<int>> matrix, int k) {
        int result = -INF;
        int n = (int)matrix.size(), m = (int)matrix.front().size();
        for (int L = 0; L < m; ++L) {
            vector<int> res_col(n, 0);
            for (int R = L; R < m; ++R) {
                for (int idx = 0; idx < n; ++idx) {
                    res_col[idx] += matrix[idx][R];
                }
                vector<int> prefix(n + 1, 0);
                for (int idx = 1; idx <= n; ++idx) {
                    prefix[idx] = prefix[idx - 1] + res_col[idx - 1];
                }
                for (int st = 1; st <= n; ++st) {
                    for (int fin = st; fin <= n; ++fin) {
                        int sum = prefix[fin] - prefix[st - 1];
                        if (sum > k) { continue; }
                        if (k - result > k - sum) {
                            result = sum;
                        }
                    }
                }
            }
        }
        return result;
    }
};
// O(N^3), 349 ms
*/

class Solution {
private:
    const int INF = (int)1e9;
public:
    int maxSumSubmatrix(vector<vector<int>> matrix, int k) {
        int result = -INF;
        int n = (int)matrix.size(), m = (int)matrix.front().size();
        for (int L = 0; L < m; ++L) {
            vector<int> res_col(n, 0);
            for (int R = L; R < m; ++R) {
                for (int idx = 0; idx < n; ++idx) {
                    res_col[idx] += matrix[idx][R];
                }
                // Find the max subarray no more than K
                set<int> prefix;
                prefix.insert(0);
                int sum_so_far = 0;
                for (int num : res_col) {
                    sum_so_far += num;
                    auto it = prefix.lower_bound(sum_so_far - k);
                    if (it != prefix.end()) {
                        // sub_arr_sum <= k because of it != prefix.end()
                        int sub_arr_sum = sum_so_far - *it;
                        if (k - sub_arr_sum < k - result) {
                            result = sub_arr_sum;
                        }
                    }
                    prefix.insert(sum_so_far);
                }
            }
        }
        return result;
    }
};
// O(N^2 logN), 243 ms

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(-1, sol.maxSumSubmatrix({{2,2,-1}}, 0));
    EXPECT_EQ(2, sol.maxSumSubmatrix({{1,  0, 1},{0, -2, 3}}, 2));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

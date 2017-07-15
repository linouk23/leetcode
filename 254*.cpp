// 254. Factor Combinations - https://leetcode.com/problems/factor-combinations

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    void helper(int n, vector<int> sorted_res_so_far) {
        int min_div = sorted_res_so_far.empty() ? 2 : sorted_res_so_far.back();
        // Trick: implicit sorting.
        for (; min_div <= (int)sqrt(n); ++min_div) {
//        for (; min_div <= n / min_div; ++min_div) {
            if (n % min_div != 0) { continue; }
            sorted_res_so_far.emplace_back(min_div);
            sorted_res_so_far.emplace_back(n / min_div);
            // {2, 6}
            result.emplace_back(sorted_res_so_far);
            sorted_res_so_far.pop_back();
            // {2}
            // helper(6, {2}) -> {2, 2, 3} -> helper(3, {2, 2}) -> return
            helper(n / min_div, sorted_res_so_far);
            sorted_res_so_far.pop_back();
        }
    }
public:
    vector<vector<int>> getFactors(int n) {
        helper(n, {});
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_TRUE(sol.getFactors(1).empty());
    EXPECT_TRUE(sol.getFactors(37).empty());
    vector<vector<int>> expected = {
        {2, 6}, {2, 2, 3}, {3, 4},
    };
    EXPECT_EQ(expected, sol.getFactors(12));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

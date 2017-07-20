// 556. Next Greater Element III - https://leetcode.com/problems/next-greater-element-iii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        auto str = to_string(n);
        // {6, 2, 1, 5, 4, 3, 0} -> {0, 3, 4, 5, 1, 2, 6} -> 1
        auto break_point = is_sorted_until(str.rbegin(), str.rend());
        
        bool has_next_one = !(break_point == str.rend());
        if (!has_next_one) {
            return -1;
        }
        
        // {0, 3, 4, 5}, x > 1 -> 3
        auto least_upper_bound = upper_bound(str.rbegin(), break_point, *break_point);
        
        // {6, 2, 1, 5, 4, 3, 0} -> {6, 2, 3, 5, 4, 1, 0}
        iter_swap(break_point, least_upper_bound);
        
        // Since the suffix is sorted, reverse == sort:
        // {6, 2, 3, 5, 4, 1, 0} -> {6, 2, 3, 0, 1, 4, 5}
        reverse(str.rbegin(), break_point);
        return stoll(str) > INT_MAX ? -1 : stoi(str);
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(21, sol.nextGreaterElement(12));
    EXPECT_EQ(-1, sol.nextGreaterElement(21));
    EXPECT_EQ(-1, sol.nextGreaterElement(1999999999));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

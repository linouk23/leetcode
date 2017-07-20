// 456. 132 Pattern - https://leetcode.com/problems/132-pattern

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Idea: inc seq in stack, keep the last popped out element (max
// to the right) [ 9, 11, 8, 9, 10, 7, 9 ], [10] and el = 9 -> 8
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int last_popped = INT_MIN;
        stack<int> st;
        int n = (int)nums.size();
        for (int idx = n - 1; idx >= 0; --idx) {
            if (nums[idx] < last_popped) { return true; }
            else {
                // Keep inc seq in the stack
                while (!st.empty() && nums[idx] > st.top()) {
                    last_popped = st.top(); st.pop();
                }
                st.push(nums[idx]);
            }
        }
        return false;
    }
};
    
int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

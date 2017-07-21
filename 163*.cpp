// 163. Missing Ranges - https://leetcode.com/problems/missing-ranges

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ranges;
        // Next - a number we want to find.
        // 5 -> next = 6
        int next = lower;
        for (int idx = 0; idx < nums.size(); ++idx) {
            if (nums[idx] == next) {
                // Next is not missing, so continue.
                next += 1;
                continue;
            }
            // Next is missing.
            ranges.emplace_back(getRange(next, nums[idx] - 1));
            next = nums[idx] + 1;
        }
        if (next <= upper) {
            ranges.emplace_back(getRange(next, upper));
        }
        return ranges;
    }
    
    string getRange(int L, int R) {
        if (L == R) {
            return to_string(L);
        } else {
            return to_string(L) + "->" + to_string(R);
        }
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

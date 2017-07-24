// 645. Set Mismatch - https://leetcode.com/problems/set-mismatch

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> countTable;
        for (int num : nums) {
            countTable[num] += 1;
        }
        int twice, never;
        for (int num = 1; num <= (int)nums.size(); ++num) {
            if (countTable[num] == 0) {
                never = num;
            } else if (countTable[num] == 2) {
                twice = num;
            }
        }
        return { twice, never };
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

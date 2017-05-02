// 532. K-diff Pairs in an Array - https://leetcode.com/problems/k-diff-pairs-in-an-array

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int, int> > myset;
        for (int i = 0; i < (int)nums.size(); ++i) {
            for (int j = i + 1; j < (int)nums.size(); ++j) {
                if (abs(nums[i] - nums[j]) != k) { continue; }
                myset.insert({min(nums[i], nums[j]), max(nums[i], nums[j])});
            }
        }
        return (int)myset.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

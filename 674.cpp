// 674. Longest Continuous Increasing Subsequence - https://leetcode.com/problems/longest-continuous-increasing-subsequence

#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9;

class Solution {
public:
    int findLengthOfLCIS(const vector<int>& nums) {
        Result result;
        if (nums.empty()) { return result.maxLength; }
        
        for (int num : nums) {
            bool shouldContinueSubsequence = num > result.prevNumber;
            if (shouldContinueSubsequence) {
                result.continueSubsequence(num);
            } else {
                result.reset(num);
            }
        }
        return result.maxLength;
    }
private:
    struct Result {
        int currentLength, maxLength, prevNumber;
        Result(): currentLength(0), maxLength(0), prevNumber(-INF) {}
        void continueSubsequence(int num) {
            currentLength += 1;
            maxLength = max(maxLength, currentLength);
            prevNumber = num;
        }
        void reset(int num) {
            maxLength = max(maxLength, currentLength);
            currentLength = 1;
            prevNumber = num;
        }
    };
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> nums = {1, 3, 5, 4, 7};
    assert(solution.findLengthOfLCIS(nums) == 3);

    nums = {2, 2, 2, 2, 2, 2};
    assert(solution.findLengthOfLCIS(nums) == 1);
    
    
    nums = {2, 1, 3};
    assert(solution.findLengthOfLCIS(nums) == 2);

    return 0;
}
// 229. Majority Element II - https://leetcode.com/problems/majority-element-ii

#include "bits/stdc++.h"

using namespace std;

// https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
class Solution {
private:
    bool check(int element, vector<int> &nums, int n) {
        int count = 0;
        for (int num : nums) {
            if (element == num) { ++count; }
        }
        return count > n / 3;
    }
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = (int)nums.size();
        if (len == 0) { return nums; }
        int result1, result2, count1, count2;
        result1 = 0;
        result2 = 1;
        count1 = count2 = 0;
        for (int n : nums) {
            if (n == result1) {
                ++count1;
            } else if (n == result2) {
                ++count2;
            } else if (count1 == 0) {
                result1 = n;
                count1 = 1;
            } else if (count2 == 0) {
                result2 = n;
                count2 = 1;
            } else {
                --count1;
                --count2;
            }
        }

        vector<int> result;
        if (check(result1, nums, len)) {
            result.emplace_back(result1);
        }
        if (check(result2, nums, len)) {
            result.emplace_back(result2);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

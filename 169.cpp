// 169. Majority Element - https://leetcode.com/problems/majority-element

#include "bits/stdc++.h"

using namespace std;

// https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = (int)nums.size();
        int result = 0;
        int count = 0;
        for (int num : nums) {
            if (count == 0) { 
                result = num;
            }
            if (result == num) {
                ++count;
            } else {
                --count;
            }

        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

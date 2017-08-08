// 216. Combination Sum III - https://leetcode.com/problems/combination-sum-iii

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int NUM_OF_DIGITS = 10;
    vector<vector<int>> result;
    
    void helper(deque<bool> used, int start, int terms_left, int target) {
        if (target < 0 || terms_left < 0) { return; }
        if (target == 0 && terms_left == 0) {
            vector<int> cur;
            for (int idx = 1; idx < NUM_OF_DIGITS; ++idx) {
                if (!used[idx]) { continue; }
                cur.emplace_back(idx);
            }
            result.push_back(cur);
            return;
        }
        
        for (int digit = start; digit < NUM_OF_DIGITS; ++digit) {
            if (used[digit]) { continue; }
            used[digit] = true;
            helper(used, digit + 1, terms_left - 1, target - digit);
            used[digit] = false;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        deque<bool> used(NUM_OF_DIGITS, false);
        // Trick.
        // Use a start digit.
        helper(used, 1, k, n);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

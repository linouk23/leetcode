// 484. Find Permutation - https://leetcode.com/problems/find-permutation

#include "bits/stdc++.h"

using namespace std;

//https://discuss.leetcode.com/topic/76276/1-liner-and-5-liner-visual-explanation
//If it's all just I, then the answer is the numbers in ascending order.
//And if there are streaks of D, then just reverse the number streak under each.

class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = (int)s.length();
        vector<int> result(n + 1);
        // 1, 2, 3, ..., n + 1
        iota(result.begin(), result.end(), 1);
        
        for (int idx = 0; idx < n; ++idx) {
            if (s[idx] != 'D') { continue; }
            int L = idx;
            while (L < n && s[idx] == 'D') { ++idx; }
            int R = idx;
            // Reverse [L, R] == [L, R + 1)
            reverse(result.begin() + L, result.begin() + R + 1);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

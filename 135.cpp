// 135. Candy - https://leetcode.com/problems/candy

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = (int)ratings.size();
        vector<int> candies(n, 1);
        // L -> R
        for (int idx = 1; idx < n; ++idx) {
            if (ratings[idx] > ratings[idx - 1]) {
                candies[idx] = candies[idx - 1] + 1;
            }
        }
        // R -> L
        for (int idx = n - 2; idx >= 0; --idx) {
            if (ratings[idx] > ratings[idx + 1]) {
                candies[idx] = max(candies[idx], candies[idx + 1] + 1);
            }
        }
        int result = accumulate(candies.begin(), candies.end(), 0);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

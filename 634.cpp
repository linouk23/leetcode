// 634. Find the Derangement of An Array - https://leetcode.com/problems/find-the-derangement-of-an-array

#include "bits/stdc++.h"

using namespace std;

// Inclusion exclusion principle
// Or https://en.wikipedia.org/wiki/Derangement#Counting_derangements
// D(N) = (N-1) * (D(N-1) + D(N-2))
// (a * b) mod m = (a mod m * b mod m) mod m
// (a + b) mod m = (a mod m + b mod m) mod m
class Solution {
public:
    int findDerangement(int n) {
        const unsigned long long mod = 1e9 + 7;
        vector<unsigned long long> dp(n + 3);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (int k = 3; k <= n; ++k) {
            dp[k] = ((dp[k - 1] % mod) + (dp[k - 2] % mod)) % mod;
            dp[k] = (dp[k] * (k - 1)) % mod;
        }
        return (int)dp[n];
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

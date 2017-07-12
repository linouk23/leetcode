// 276. Paint Fence - https://leetcode.com/problems/paint-fence

#include "bits/stdc++.h"

using namespace std;

// There is a fence with n posts, each post can be painted
// with one of the k colors. You have to paint all the posts
// such that no more than two adjacent fence posts have the
// same color. Return the total number of ways you can paint the fence.

class Solution {
public:
    int numWays(int n, int k) {
        // Let dp[k][j] be the total number of ways to paint (the 1st) k posts
        // such that no more than two adjacent fence posts have the
        // same color and there're j in a row posts in the end which
        // have the same color.
        vector<vector<int>> dp(n + 10, vector<int> (3, 0));
        // dp[0][any] = 0
        for (int idx = 1; idx <= n; ++idx) {
            // For any color c: ****ac, ****bc -> ****acc, ****bcc = 2
            dp[n][2] = dp[n - 1][1];
            
            // If we fix color => there're k - 1 colors left, so we use
            // them to change last color:
            // a -> ab, ac, ..., ak -> k - 1
            // b -> ba, bc, ..., bk -> k - 1
            // a + b + ... = M -> (a + b + ...) * (k - 1) = M * (k - 1)
            
            // aa -> aab, aac, ..., aak -> k - 1
            // bb -> bba, bbc, ..., bbk -> k - 1
            // aa + bb + ... = L -> (aa + bb + ...) * (k - 1) = L * (k - 1)
            // M * (k - 1) + L * (k - 1) = (k - 1) (L + M)
            dp[n][1] = (k - 1) * (dp[n - 1][2] + dp[n - 1][1]);
        }
        return dp[n][1] + dp[n][2];
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

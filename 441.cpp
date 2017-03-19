// 441. Arranging Coins - https://leetcode.com/problems/arranging-coins

#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    bool can_fill_M_levels(long long n, long long M) {
        long long required_sum_to_fill = M * (M + 1) / 2;
        return (n >= required_sum_to_fill);
    }

    int arrangeCoins(int n) {
        long long L = -1, R = (long long)n + 1;
        // 111100000000000000
        while(R - L > 1) {
            long long M = L + (R - L) / 2;
            if (can_fill_M_levels(n, M)) {
                L = M;
            } else {
                R = M;
            }
        }
        return L;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.arrangeCoins(0) == 0);
    assert(solution.arrangeCoins(1) == 1);
    assert(solution.arrangeCoins(5) == 2);
    assert(solution.arrangeCoins(8) == 3);
    assert(solution.arrangeCoins(2147483647) == 65535);

    return 0;
}

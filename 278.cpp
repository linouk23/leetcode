// 278. First Bad Version - https://leetcode.com/problems/first-bad-version

#include <bits/stdc++.h>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long L = 1LL - 1;
        long long R = 1LL * n + 1;
        while(R - L > 1) {
            long long M = L + (R - L) / 2;
            if (isBadVersion(M)) {
                R = M;
            } else {
                L = M;
            }
        }
        return R;
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

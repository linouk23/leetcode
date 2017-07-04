// 397. Integer Replacement - https://leetcode.com/problems/integer-replacement

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int integerReplacement(int num) {
        queue<pair<long long, int>> q;
        q.push({num, 0});
        int level;
        long long n;
        while(!q.empty()) {
            tie(n, level) = q.front();
            if (n == 1) { break; }
            q.pop();
            if (n % 2 == 0) {
                q.push({n / 2LL, level + 1});
            } else {
                q.push({n + 1LL, level + 1});
                q.push({n - 1LL, level + 1});
            }
        }
        return q.front().second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

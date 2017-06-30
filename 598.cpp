// 598. Range Addition II - https://leetcode.com/problems/range-addition-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>> ops) {
        for (const auto &op : ops) {
            m = min(op[0], m);
            n = min(op[1], n);
        }
        return m * n;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

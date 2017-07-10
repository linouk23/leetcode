// 89. Gray Code - https://leetcode.com/problems/gray-code

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        auto g = [](int idx) {
            return idx ^ (idx >> 1);
        };
        vector<int> result;
        // |00101...| = n -> 2^n combinations in total
        for (int idx = 0; idx < (1 << n); ++idx) {
            result.emplace_back(g(idx));
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

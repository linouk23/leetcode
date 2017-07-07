// 42. Trapping Rain Water - https://leetcode.com/problems/trapping-rain-water

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int)height.size();
        if (n == 0) { return 0; }
        vector<int> maxL(n);
        auto maxR = maxL;
        maxL[0] = 0;
        for (int idx = 1; idx < n; ++idx) {
            maxL[idx] = max(maxL[idx - 1], height[idx - 1]);
        }
        maxL[n - 1] = 0;
        for (int idx = n - 2; idx >= 0; --idx) {
            maxR[idx] = max(maxR[idx + 1], height[idx + 1]);
        }
        int result = 0;
        for (int idx = 1; idx <= n - 2; ++idx) {
            result += max(0, min(maxL[idx], maxR[idx]) - height[idx]);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

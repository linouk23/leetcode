// 370. Range Addition - https://leetcode.com/problems/range-addition

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length + 1, 0);
        int startIndex, finishIndex, inc;
        for (auto &e : updates) {
            startIndex = e[0], finishIndex = e[1], inc = e[2];
            result[startIndex] += inc;
            result[finishIndex + 1] -= inc;
        }
        
        // Reconstruct array
        for (int idx = 1; idx < length; ++idx) {
            result[idx] += result[idx - 1];
        }
        
        // Trick.
        result.pop_back();
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

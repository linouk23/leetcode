// 566. Reshape the Matrix - https://leetcode.com/problems/reshape-the-matrix

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = (int)nums.size();
        int m = (int)nums[0].size();
        if (n * m != r * c) { return nums; }
        vector<vector<int> > result(r, vector<int> (c));
        for (int index = 0; index < n * m; ++index) {
            result[index / c][index % c] = nums[index / m][index % m];
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

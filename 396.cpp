// 396. Rotate Function - https://leetcode.com/problems/rotate-function

#include "bits/stdc++.h"

using namespace std;

//Consider we have 5 coins A,B,C,D,E:
//According to the problem statement
//F(0) = (0A) + (1B) + (2C) + (3D) + (4E)
//F(1) = (4A) + (0B) + (1C) + (2D) + (3E)
//F(2) = (3A) + (4B) + (0C) + (1D) + (2*E)
//
//We can construct F(1) from F(0) by two steps:
//Step 1. taking away one count of each coin from F(0):
//After step 1 F(0) = (-1A) + (0B) + (1C) + (2D) + (3*E)
//
//Step 2. Add n times the element which didn't contributed in F(0), which is A.
//After step 2 F(0) = (4A) + (0B) + (1C) + (2D) + (3E)

//F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].
//Calculate the maximum value of F(0), F(1), ..., F(n-1).

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) { return 0; }
        int n = (int)A.size();
        int sum = accumulate(A.begin(), A.end(), 0);
        
        int val = 0;
        // F(0):
        for (int idx = 0; idx < n; ++idx) {
            val += A[idx] * idx;
        }
        int result = val;
        // F(iter):
        for (int iter = 1; iter < n; ++iter) {
            // Step #1:
            val -= sum;
            // Step #2:
            val += A[iter - 1] * n;
            
            result = max(result, val);
        }
        
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

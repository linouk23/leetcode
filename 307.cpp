// 307. Range Sum Query - Mutable - https://leetcode.com/problems/range-sum-query-mutable

#include "bits/stdc++.h"

using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        vec = nums;
        n = nextPowerOf2((int)nums.size());
        vec.resize(2 * n, 0);
        buildTree();
    }
    
    void update(int i, int val) {
        int index = i + n;
        vec[index] = val;
        for (index /= 2; index >= 1; index /= 2) {
            vec[index] = vec[2 * index] + vec[2 * index + 1];
        }
    }
    
    int sumRange(int i, int j) {
        int L = i + n;
        int R = j + n;
        int sum = 0;
        while (L <= R) {
            if (L % 2 == 1) { sum += vec[L++]; }
            if (R % 2 == 0) { sum += vec[R--]; }
            L /= 2;
            R /= 2;
        }
        return sum;
    }
private:
    int n;
    vector<int> vec;
    int nextPowerOf2(int n) {
        int L = -1, R = 32;
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if ((1 << M) >= n) {
                R = M;
            } else {
                L = M;
            }
        }
        return (1 << R);
    }
    void buildTree() {
        for (int index = 0; index < n; ++index) {
            vec[index + n] = vec[index];
        }
        for (int index = n - 1; index >= 1; --index) {
            vec[index] = vec[2 * index] + vec[2 * index + 1];
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
    return 0;
}


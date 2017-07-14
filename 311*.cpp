// 311. Sparse Matrix Multiplication - https://leetcode.com/problems/sparse-matrix-multiplication

#include "bits/stdc++.h"

using namespace std;

//It should be a data structure design problem.
//You should give a reasonable data structure to present sparse
//matrix and multiplication method.

//http://www.cs.cmu.edu/~scandal/cacm/node9.html
//       2.0    -1.0    0        0
// A =  -1.0    2.0    -1.0      0
//        0     -1.0    2.0    -1.0
//        0      0     -1.0     2.0
//is represented in this way as
//A = [[(0, 2.0), (1, -1.0)],
//     [(0, -1.0), (1, 2.0), (2, -1.0)],
//     [(1, -1.0), (2, 2.0), (3, -1.0)],
//     [(2, -1.0), (3, 2.0)]]
//where A is a nested sequence. This representation can be used for matrices with arbitrary patterns of nonzero elements since each subsequence can be of a different size.

//class Solution {
//public:
//};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

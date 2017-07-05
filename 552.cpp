// 552. Student Attendance Record II - https://leetcode.com/problems/student-attendance-record-ii

#include "bits/stdc++.h"

using namespace std;

// MLE
//class Solution {
//private:
//    const int mod = (int)1e9 + 7;
//    void add(int &a, int &b) {
//        a = (a % mod + b % mod) % mod;
//    }
//public:
//    int checkRecord(int n) {
//        // Let dp[i][j][k] be the total number of
//        // of valid records with length i, containing i 'A' symbols
//        // and ending with k consecutive 'L'.
//        vector<vector<vector<int> > > dp(n + 1,
//               vector<vector<int> > (2, vector<int> (3, 0)));
//        dp[1][0][0] = 1; // |{'P'}|
//        dp[1][0][1] = 1; // |{'L'}|
//        dp[1][1][0] = 1; // |{'A'}|
//        
//        for (int len = 2; len <= n; ++len) {
//            // Student was 'P' on nth day:
//            for (int A = 0; A <= 1; ++A) {
//                for (int L = 0; L <= 2; ++L) {
//                    add(dp[len][A][0], dp[len - 1][A][L]);
//                }
//            }
//            
//            // Student was 'L' on nth day:
//            for (int A = 0; A <= 1; ++A) {
//                for (int L = 1; L <= 2; ++L) {
//                    add(dp[len][A][L], dp[len - 1][A][L - 1]);
//                }
//            }
//            
//            // Student was 'A' on nth day:
//            for (int L = 0; L <= 2; ++L) {
//                add(dp[len][1][0], dp[len - 1][0][L]);
//            }
//        }
//        int result = 0;
//        for (int A = 0; A <= 1; ++A) {
//            for (int L = 0; L <= 2; ++L) {
//                add(result, dp[n][A][L]);
//            }
//        }
//        return result;
//    }
//};

// OK, O(N) time, O(1) space.
//class Solution {
//private:
//    const int mod = (int)1e9 + 7;
//    void add(int &a, int &b) {
//        a = (a % mod + b % mod) % mod;
//    }
//public:
//    int checkRecord(int n) {
//        if (n == 1) { return 3; }
//        // Let dp[i][j][k] be the total number of
//        // of valid records with length i, containing i 'A' symbols
//        // and ending with k consecutive 'L'.
//        vector<vector<int> > cur(2, vector<int> (3, 0));
//        auto prev = cur;
//        prev[0][0] = 1; // |{'P'}|
//        prev[0][1] = 1; // |{'L'}|
//        prev[1][0] = 1; // |{'A'}|
//        
//        for (int len = 2; len <= n; ++len) {
//            cur.assign(2, vector<int> (3, 0));
//            // Student was 'P' on nth day:
//            for (int A = 0; A <= 1; ++A) {
//                for (int L = 0; L <= 2; ++L) {
//                    add(cur[A][0], prev[A][L]);
//                }
//            }
//            
//            // Student was 'L' on nth day:
//            for (int A = 0; A <= 1; ++A) {
//                for (int L = 1; L <= 2; ++L) {
//                    add(cur[A][L], prev[A][L - 1]);
//                }
//            }
//            
//            // Student was 'A' on nth day:
//            for (int L = 0; L <= 2; ++L) {
//                add(cur[1][0], prev[0][L]);
//            }
//            prev = cur;
//        }
//        int result = 0;
//        for (int A = 0; A <= 1; ++A) {
//            for (int L = 0; L <= 2; ++L) {
//                add(result, cur[A][L]);
//            }
//        }
//        return result;
//    }
//};

// OK, O(6^3 logN) time, O(1) space.
// dp_n = (dp_n|0|0, dp_|0|1, dp_n|0|2, dp_n|1|0, dp_n|1|1, dp_n|1|2)^T
// dp_n = A * dp_{n-1}
//        -                                                                    -
//       | dp_n-1|00 + dp_n-1|01 + dp_n-1|02                                    |
//       | dp_n-1|00                                                            |
// dp_n =| dp_n-1|01                                                            |
//       | dp_n-1|00 + dp_n-1|01 + dp_n-1|02 + dp_n-1|10 + dp_n-1|11 + dp_n-1|12|
//       | dp_n-1|10                                                            |
//       | dp_n-1|11                                                            |
//        -                                                                    -
// => dp_n = A^n * dp_0 = A^{n - 1} * dp_1 -> [A = KxK, K = 6] =>
// O(6^3 logN) time, O(1) space.
class Solution {
private:
    const int mod = (int)1e9 + 7;
    void add(int &a, const int &b) {
        a = (a % mod + b % mod) % mod;
    }
    void add(long long &a, const long long &b) {
        a = (a % mod + b % mod) % mod;
    }
    
    vector<vector<int>> mult(const vector<vector<int>> &A, const vector<vector<int>> &B) {
        int N = (int)A.size();
        int M = (int)B[0].size();
        vector<vector<int> > result(N, vector<int> (M, 0));
        int K = (int)A[0].size();
        for (int row = 0; row < N; ++row) {
            for (int col = 0; col < M; ++col) {
                // Mult itself
                long long result_value = 0;
                for (int k = 0; k < K; ++k) {
                    add(result_value, 1LL * A[row][k] * B[k][col]);
                }
                result[row][col] = (int)result_value;
            }
        }
        return result;
    }
    
    vector<vector<int> > matrix_power(vector<vector<int> > &A, int n) {
        int N = (int)A.size();
        int M = (int)A[0].size();
        vector<vector<int> > result(N, vector<int> (M)); // = identity matrix I
        for (int row = 0; row < N; ++row) {
            result[row][row] = 1;
        }
        auto cur_matrix_power = A; // A^1
        // n = 6=0b110-> result = A^1 + A^2, |110| = (int)log_2 6 + 1
        // 0b 1    1   0
        //    2^2 2^1 2^0 => 0 * 2^0 + 1 * 2^1 + 1 * 2^2
        // k^6 => 0 * k^{2^0} + 1 * k^{2^1} + 1 * k^{2^2}, k^{2^0} = A
        while (n > 0) {
            if (n % 2) {
                result = mult(result, cur_matrix_power);
            }
            n >>= 1;
            // cur_matrix_power = cur_matrix_power^2
            cur_matrix_power = mult(cur_matrix_power, cur_matrix_power);
        }
        return result;
    }
public:
    int checkRecord(int n) {
        vector<vector<int> > dp_1 = {{1}, {1}, {0}, {1}, {0}, {0}};
        vector<vector<int> > A = {
            {1, 1, 1, 0, 0, 0},
            {1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0},
        };
        // dp_n = A^{n - 1} * dp_1 = A^n * dp_0
        auto A_n_minus_one = matrix_power(A, n - 1);
        auto dp_n = mult(A_n_minus_one, dp_1);
        int result = 0;
        for (const auto &vec : dp_n) {
            for (const int &el : vec) {
                add(result, el);
            }
        }
        return result;
    }
};


int main() {
    ios::sync_with_stdio(false);
    return 0;
}

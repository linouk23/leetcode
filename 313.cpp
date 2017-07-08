// 313. Super Ugly Number - https://leetcode.com/problems/super-ugly-number

#include "bits/stdc++.h"

using namespace std;

// In order to produce a new smallest ugly number, one of (or some of) 2, 3, 5
// needs to multiply a smaller ugly number, and there come the pointers.
// After an ugly number is produced, the corresponding pointer(s) needs to move forward.
// Otherwise it will produce the same ugly number.
// And the order is retained since each product is larger or equal than before and we extract the minimum every time.

class Solution {
private:
    const int MAX_VAL_OF_PRIME = 1234;
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // nums[1] = min(nums[0] * 2, nums[0] * 3, nums[0] * 5)
        // If we don't change 'pointers', it'll produce the same ugly number.
        int k = (int)primes.size();
        vector<int> pointers(MAX_VAL_OF_PRIME + 1, 0);
        if (n <= 0) { return 0; }
        if (n == 1) { return 1; }
        vector<int> ugly_nums(n + 10);
        ugly_nums[0] = 1;
        for (int k = 1; k <= n - 1; ++k) {
            int next_min_num = INT_MAX;
            for (int prime : primes) {
                next_min_num = min(next_min_num,
                                   ugly_nums[pointers[prime]] * prime);
            }
            ugly_nums[k] = next_min_num;
            for (int prime : primes) {
                if (ugly_nums[k] == ugly_nums[pointers[prime]] * prime) {
                    ++pointers[prime];
                }
            }
        }
        return ugly_nums[n - 1];
    }
};



int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 60. Permutation Sequence - https://leetcode.com/problems/permutation-sequence

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        unordered_map<int, int> fact;
        fact[0] = 1;
        int temp = 1;
        for (int idx = 1; idx <= n; ++idx) {
            temp *= idx;
            fact[idx] = temp;
        }
        vector<int> nums;
        for (int digit = 1; digit <= 9; ++digit) {
            nums.emplace_back(digit);
        }
        string result = "";
        // n = 4, k = 8
        // 1 + {2, 3, 4} 1...6
        // 2 + {1, 3, 4} 7...12
        // 3 + {1, 2, 4} 13...18
        // 4 + {1, 2, 3} 19...24
        for (int idx = 0; idx < n; ++idx) {
            int fact_of_n_minus_one = fact[n - idx - 1];
            // 8 / 6 => 2...
            int digit_index = ceil(double(k) / double(fact_of_n_minus_one)) - 1;
            int digit_to_insert = nums[digit_index];
            nums.erase(nums.begin() + digit_index);
            result += to_string(digit_to_insert);
            k -= digit_index * fact_of_n_minus_one;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

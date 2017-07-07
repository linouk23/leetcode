// 201. Bitwise AND of Numbers Range - https://leetcode.com/problems/bitwise-and-of-numbers-range

#include "bits/stdc++.h"

using namespace std;

// Longest common prefix;
// like for decimals:
// 6002333
// 6002612 -> 6002
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        const int INT_SIZE = 32;
        bitset<INT_SIZE> fst_num(m);
        bitset<INT_SIZE> snd_num(n);
        bitset<INT_SIZE> result;
        int idx_fst_one = INT_SIZE;
        for (int idx = INT_SIZE - 1; idx >= 0; --idx) {
            if (fst_num[idx]) {
                idx_fst_one = idx;
                break;
            }
        }
        
        for (int idx = INT_SIZE - 1; idx >= 0; --idx) {
            if (snd_num[idx]) {
                if (idx_fst_one != idx) { return 0; };
                break;
            }
        }
        if (idx_fst_one < INT_SIZE) {
            result[idx_fst_one] = 1;
        }
        for (int idx = idx_fst_one - 1; idx >= 0; --idx) {
            //cout << result.to_string() << endl;
            if (fst_num[idx] == snd_num[idx]) {
                result[idx] = fst_num[idx];
            } else {
                break;
            }
        }
        return (int)result.to_ulong();
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

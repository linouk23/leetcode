// 246. Strobogrammatic Number - https://leetcode.com/problems/strobogrammatic-number

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> hashtable = {
            {'0', '0'}, {'1', '1'}, {'8', '8'},
            {'6', '9'}, {'9', '6'},
        };
        int L = 0;
        int R = (int)num.length() - 1;
        while (L <= R) {
            if (!hashtable.count(num[L]) || !hashtable.count(num[R])) {
                return false;
            }
            if (hashtable[num[L]] != num[R]) {
                return false;
            }
            ++L; --R;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

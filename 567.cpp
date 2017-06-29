// 567. Permutation in String - https://leetcode.com/problems/permutation-in-string

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int count = (int)s1.length();
        int L = 0, R = 0;
        
        vector<int> table_counter(26, 0);
        for (char ch : s1) {
            table_counter[ch - 'a'] += 1;
        }
        while (R < (int)s2.length()) {
            if (table_counter[s2[R++] - 'a']-- >= 1) {
                --count;
            }
            
            if (count == 0) { return true; }
            
            // [L, R) => '<=' instead of '<' => [L, R] = |s1|
            if (R - L + 1 <= s1.length()) { continue; }
            
            if (table_counter[s2[L++] - 'a']++ >= 0) {
                ++count;
            }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

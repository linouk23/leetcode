// 392. Is Subsequence - https://leetcode.com/problems/is-subsequence

#include "bits/stdc++.h"

using namespace std;
    
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int start_idx = 0;
        for (int idxs = 0; idxs < s.length(); ++idxs) {
            bool has_found = false;
            for (int idx = start_idx; idx < t.length(); ++idx) {
                if (t[idx] == s[idxs]) {
                    start_idx = idx + 1;
                    has_found = true;
                    break;
                }
            }
            if (!has_found) { return false; }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

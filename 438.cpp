// 438. Find All Anagrams in a String - https://leetcode.com/problems/find-all-anagrams-in-a-string

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int count = (int)p.length();
        int L, R;
        L = R = 0;
        vector<int> result, table_count(26, 0);
        for (char ch : p) {
            table_count[ch - 'a'] += 1;
        }
        
        // Invariant: R - L + 1 <= |p|
        // Funny +/- in table_counter.
        while (R < (int)s.length()) {
            // Counter >= 1 means the character exists in p.
            // table_count[ch] = 0 for all non-p symbols.
            if (table_count[s[R++] - 'a']-- >= 1) {
                --count;
            }
            // Found the right anagram.
            if (count == 0) { result.emplace_back(L); }
            
            // Restore counter.
            // -1 -> 0 for all non-p symbols.
            if (R - L + 1 <= p.length()) { continue; }
            if (table_count[s[L++] - 'a']++ >= 0) {
                ++count;
            }
        }
        
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

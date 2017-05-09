// 161. One Edit Distance - https://leetcode.com/problems/one-edit-distance

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = (int)s.size(), n = (int)t.size();
        if (m > n) return isOneEditDistance(t, s);
        if (n - m > 1 || s == t) return false;
        for (int i = 0; i < m; i++) {
            if (s[i] != t[i]) {
                if (m == n) {
                    s[i] = t[i];
                } else {
                    s.insert(i, 1, t[i]);
                }
                break;
            }
        }
        return s == t || s + t[n - 1] == t;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 521. Longest Uncommon Subsequence I - https://leetcode.com/problems/longest-uncommon-subsequence-i

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        return (a == b) ? -1 : max((int)a.length(), (int)b.length());
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

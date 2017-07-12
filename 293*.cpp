// 293. Flip Game - https://leetcode.com/problems/flip-game

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        int n = (int)s.length();
        for (int idx = 0; idx < n - 1; ++idx) {
            if (s[idx] == '+' && s[idx+ 1] == '+') {
                s[idx] = s[idx + 1] = '-';
                result.emplace_back(s);
                s[idx] = s[idx + 1] = '+';
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

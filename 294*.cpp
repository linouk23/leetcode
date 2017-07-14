// 294. Flip Game II - https://leetcode.com/problems/flip-game-ii

#include "bits/stdc++.h"

using namespace std;

// The idea is try to replace every "++" in the current
// string s to "--" and see if the opponent can win or not,
// if the opponent cannot win, great, we win!
// TODO: add memo {}
class Solution {
public:
    bool canWin(string s) {
        if (s.length() < 2) {
            return false;
        }
        
        for (int idx = 0; idx < (int)s.length() - 1; ++idx) {
            if (s[idx] == '+' && s[idx] + 1 == '+') {
                string stateForFriend = s.substr(0, idx) +
                                        "--" +
                                        s.substr(idx + 2);
                
                if (!canWin(stateForFriend)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

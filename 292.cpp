// 292. Nim Game - https://leetcode.com/problems/nim-game

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4);
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.canWinNim(1) == true);
    assert(solution.canWinNim(4) == false);

    return 0;
}

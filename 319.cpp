// 319. Bulb Switcher - https://leetcode.com/problems/bulb-switcher

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int result = 0;
        int sq = 1;
        while (sq * sq <= n) {
            ++result;
            ++sq;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

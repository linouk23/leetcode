// 458. Poor Pigs - https://leetcode.com/problems/poor-pigs

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        while (pow(minutesToTest / minutesToDie + 1, pigs) < buckets) {
            pigs += 1;
        }
        return pigs;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

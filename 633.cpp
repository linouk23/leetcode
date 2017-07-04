// 633. Sum of Square Numbers - https://leetcode.com/problems/sum-of-square-numbers

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    bool is_square(int n) {
        return int(sqrt(n)) * int(sqrt(n)) == n;
    }
public:
    bool judgeSquareSum(int c) {
        for (int a = 0; a <= sqrt(c); ++a) {
            if (is_square(c - a * a)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

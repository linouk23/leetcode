// 386. Lexicographical Numbers - https://leetcode.com/problems/lexicographical-numbers

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    vector<int> result;
    void helper(int n, int upper) {
        if (n > upper) { return; }
        result.emplace_back(n);
        for (int digit = 0; digit <= 9; ++digit) {
            helper(10 * n + digit, upper);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        for (int start = 1; start <= min(9, n); ++start) {
            helper(start, n);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

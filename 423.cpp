// 423. Reconstruct Original Digits from English - https://leetcode.com/problems/reconstruct-original-digits-from-english

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int NUM_OF_DIGITS = 10;
    unordered_map<char, int> chmap = {
        {'z', 0},
        {'w', 2},
        {'x', 6},
        {'s', 7},
        {'g', 8},
        {'u', 4},
        {'f', 5},
        {'h', 3},
        {'i', 9},
        {'o', 1},
    };
public:
    string originalDigits(string s) {
        vector<int> count(NUM_OF_DIGITS);
        for (char ch : s) {
            if (!chmap.count(ch)) { continue; }
            int digit = chmap[ch];
            count[digit] += 1;
        }
        count[7] -= count[6];
        count[5] -= count[4];
        count[3] -= count[8];
        count[9] = count[9] - count[8] - count[5] - count[6];
        count[1] = count[1] - count[0] - count[2] - count[4];
        string result;
        for (int digit = 0; digit < NUM_OF_DIGITS; ++digit) {
            result += string(count[digit], '0' + digit);
        }
        return result;
    }
};


int main() {
    ios::sync_with_stdio(false);
    Solution sol;
    sol.lexicalOrder(13);
    return 0;
}

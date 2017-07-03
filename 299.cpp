// 299. Bulls and Cows - https://leetcode.com/problems/bulls-and-cows

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int num_of_bulls = 0;
        int num_of_cows = 0;
        unordered_map<char, int> secretmap, guessmap;
        int n = (int)secret.length();
        for (int idx = 0; idx < n; ++idx) {
            if (secret[idx] == guess[idx]) {
                ++num_of_bulls;
            } else {
                secretmap[secret[idx]] += 1;
                guessmap[guess[idx]] += 1;
            }
        }
        for (char ch = '0'; ch <= '9'; ++ch) {
            num_of_cows += min(secretmap[ch], guessmap[ch]);
        }
        return to_string(num_of_bulls) + "A" + to_string(num_of_cows) + "B";
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

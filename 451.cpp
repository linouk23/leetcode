// 451. Sort Characters By Frequency - https://leetcode.com/problems/sort-characters-by-frequency

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch] += 1;
        }
        int n = (int)s.length();
        vector<string> bucket(n + 1);
        char ch;
        int len;
        for (const auto &p : freq) {
            tie(ch, len) = p;
            bucket[len] += string(len, ch);
        }
        string result;
        for (int len = n; len >= 1; --len) {
            result += bucket[len];
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

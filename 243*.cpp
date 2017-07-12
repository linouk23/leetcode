// 243. Shortest Word Distance - https://leetcode.com/problems/shortest-word-distance

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1, result = INT_MAX;
        int n = (int)words.size();
        for (int idx = 0; idx < n; ++idx) {
            auto word = words[idx];
            if (word == word1) {
                p1 = idx;
            }
            if (word == word2) {
                p2 = idx;
            }
            if (p1 != -1 && p2 != -1) {
                result = min(result, abs(p1 - p2));
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

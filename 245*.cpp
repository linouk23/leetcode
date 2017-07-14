// 245. Shortest Word Distance III - https://leetcode.com/problems/shortest-word-distance-iii

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        long long result = INT_MAX, last = result, snd_last = -result;
        bool isSame = (word1 == word2);
        int n = (int)words.size();
        for (int idx = 0; idx < n; ++idx) {
            auto word = words[idx];
            if (word == word1) {
                last = idx;
                if (isSame) {
                    swap(last, snd_last);
                }
            } else if (word == word2) {
                snd_last = idx;
            }
            result = min(result, abs(last - snd_last));
        }
        return (int)result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

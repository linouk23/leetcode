// 244. Shortest Word Distance II - https://leetcode.com/problems/shortest-word-distance-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        int n = (int)words.size();
        for (int idx = 0; idx < n; ++idx) {
            hashtable[words[idx]].emplace_back(idx);
        }
    }
    int shortest(string word1, string word2) {
        int idx1 = 0, idx2 = 0, dist = INT_MAX;
        int n1 = (int)hashtable[word1].size();
        int n2 = (int)hashtable[word2].size();
        while (idx1 < n1 && idx2 < n2) {
            dist = min(dist, abs(hashtable[word1][idx1] - hashtable[word2][idx2]));
            hashtable[word1][idx1]<hashtable[word2][idx2] ? ++idx1 : ++idx2;
        }
        return dist;
    }
private:
    // value is sorted
    unordered_map<string, vector<int>> hashtable;
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

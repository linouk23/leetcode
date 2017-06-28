// 72. Edit Distance - https://leetcode.com/problems/edit-distance

#include "bits/stdc++.h"

using namespace std;

const int INF = (int)1e9;

class Solution {
private:
    vector<vector<int>  > value;
    vector<vector<bool> > ready;
    
    int n, m;
    string str1, str2;
    int lazyDP(int idx1, int idx2) {
        if (idx1 < 0 || idx2 < 0)  { return INF; }
        if (idx1 == 0 && idx2 == 0) { return 0; }
        
        if (ready[idx1][idx2]) { return value[idx1][idx2]; }
        
        int best = INF;
        best = min({
            best,
            lazyDP(idx1 - 1, idx2) + 1,
            lazyDP(idx1, idx2 - 1) + 1,
            lazyDP(idx1 - 1, idx2 - 1) + (str1[idx1 - 1] == str2[idx2 - 1] ? 0 : 1),
        });
        value[idx1][idx2] = best;
        ready[idx1][idx2] = true;
        return best;
    }
    
public:
    int minDistance(string word1, string word2) {
        str1 = word1;
        str2 = word2;
        n = (int)word1.length();
        m = (int)word2.length();
        value.resize(n + 1, vector<int>  (m + 1, INF));
        ready.resize(n + 1, vector<bool> (m + 1, false));
        return lazyDP(n, m);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

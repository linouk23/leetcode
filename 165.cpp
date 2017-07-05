// 165. Compare Version Numbers - https://leetcode.com/problems/compare-version-numbers

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        vector<string> tokens1, tokens2;
        string token;
        char delim = '.';
        while(getline(ss1, token, delim)) {
            tokens1.emplace_back(token);
        }
        while(getline(ss2, token, delim)) {
            tokens2.emplace_back(token);
        }
        int n1 = (int)tokens1.size();
        int n2 = (int)tokens2.size();
        int n = max(n1, n2);
        for (int idx = 0; idx < n; ++idx) {
            int v1 = idx < n1 ? stoi(tokens1[idx]) : 0;
            int v2 = idx < n2 ? stoi(tokens2[idx]) : 0;
            if (v1 != v2) {
                return v1 < v2 ? -1 : 1;
            }
        }
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

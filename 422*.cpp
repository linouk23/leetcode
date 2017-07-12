// 422. Valid Word Square - https://leetcode.com/problems/valid-word-square

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if (words.empty()) { return true; }
        if (words.size() != words[0].size()) { return false; }
        for (int idx1 = 0; idx1 < words.size(); ++idx1) {
            for (int idx2 = 0; idx2 < words[idx1].size(); ++idx2) {
                if (idx2 >= (int)words.size()) { return false; }
                if (idx1 >= (int)words[idx2].length()) { return false; }
                if (words[idx1][idx2] != words[idx2][idx1]) { return false; }
            }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

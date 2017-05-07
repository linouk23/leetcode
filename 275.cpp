// 275. H-Index II - https://leetcode.com/problems/h-index-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = (int)citations.size();
        if (n == 0) { return 0; }
        int L = -1, R = n;
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (citations[M] >= n - M) {
                R = M;
            } else {
                L = M;
            }
        }
        return n - R;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

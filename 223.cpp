// 223. Rectangle Area - https://leetcode.com/problems/rectangle-area

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaA = (C-A) * (D-B);
        int areaB = (G-E) * (H-F);
        
        int left = max(A, E);
        int right = min(G, C);
        int bottom = max(F, B);
        int top = min(D, H);
        
        int overlap = 0;
        // In case rectangles overlap.
        if(right > left && top > bottom) {
            overlap = (right - left) * (top - bottom);
        }
        return areaA + areaB - overlap;
    }
};


int main() {
    ios::sync_with_stdio(false);
    return 0;
}

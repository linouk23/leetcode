// 492. Construct the Rectangle - https://leetcode.com/problems/construct-the-rectangle

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int best_ans = INT_MAX;
        vector<int> ans = {-1, -1};
        for (int mult = 1; mult * mult <= area; ++mult) {
            if (area % mult) continue;
            if ((area / mult) - mult < best_ans) {
                ans = {(area / mult), mult};
            };
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

// 539. Minimum Time Difference - https://leetcode.com/problems/minimum-time-difference

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (const auto &str : timePoints) {
            minutes.emplace_back(stoi(str.substr(0, 2)) * 60 +
                                 stoi(str.substr(3, 2)));
        }
        sort(minutes.begin(), minutes.end());
        int min_diff = 24 * 60 - minutes.back() + minutes.front();
        for (int idx = 1; idx < (int)minutes.size(); ++idx) {
            min_diff = min(min_diff,
                           minutes[idx] - minutes[idx - 1]);
        }
        return min_diff;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

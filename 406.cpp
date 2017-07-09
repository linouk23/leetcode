// 406. Queue Reconstruction by Height - https://leetcode.com/problems/queue-reconstruction-by-height

#include "bits/stdc++.h"

using namespace std;

struct Choice {
    int idx, height;
};

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> people) {
        auto tmp = people;
        int n = (int)people.size();
        vector<bool> used(n, false);
        vector<pair<int, int>> result;
        int count, height;
        for (int it = 0; it < n; ++it) {
            // idx, height
            Choice choice {INT_MAX, INT_MAX};
            for (int idx = 0; idx < n; ++idx) {
                if (used[idx]) { continue; }
                tie(height, count) = tmp[idx];
                if (count != 0) { continue; }
                if (height < choice.height) {
                    choice = {idx, height};
                }
            }
            used[choice.idx] = true;
            result.emplace_back(people[choice.idx]);
            // Subtract from the rest of the people.
            for (int idx = 0; idx < n; ++idx) {
                if (used[idx]) { continue; }
                tie(height, std::ignore) = tmp[idx];
                if (height <= choice.height) {
                    tmp[idx].second -= 1;
                }
            }
        }
        return result;
    }
};



int main() {
    ios::sync_with_stdio(false);
    return 0;
}

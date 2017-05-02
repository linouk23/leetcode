// 554. Brick Wall - https://leetcode.com/problems/brick-wall

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> hashmap;
        int height = (int)wall.size();
        for (auto row : wall) {
            int sum = 0;
            for (int index = 0; index < row.size() - 1; ++index) {
                int brick = row[index];
                sum += brick;
                hashmap[sum] += 1;
            }
        }
        pair<int, int> result = {0, 0};
        for (const auto & it : hashmap) {
            if (it.second > result.second) {
                result = it;
            }
        }
        return height - result.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

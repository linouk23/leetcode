// 447. Number of Boomerangs - https://leetcode.com/problems/number-of-boomerangs

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if (points.empty()) { return 0; }
        int result = 0;
        auto get_sq_dist = [](const pair<int, int> &p1, const pair<int, int> &p2) -> int {
            int diff_x = p1.first - p2.first;
            int diff_y = p1.second - p2.second;
            return pow(diff_x, 2) + pow(diff_y, 2);
        };
        for (const auto &p1 : points) {
            unordered_map<int, int> hashmap;
            for (const auto &p2 : points) {
                if (p1 == p2) { continue; }
                hashmap[get_sq_dist(p1, p2)] += 1;
            }
            for (const auto &it : hashmap) {
                int size = it.second;
                if (size < 2) { continue; }
                result += size * (size - 1);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
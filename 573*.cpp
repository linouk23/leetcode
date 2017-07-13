// 573. Squirrel Simulation - https://leetcode.com/problems/squirrel-simulation

#include "bits/stdc++.h"

using namespace std;

//Proof: Let the minimum distance from each nut to the
//tree be a_1, ..., a_n and let the minimum distance from
//each nut to the initial squirrel position be b_1, ..., b_n.
//Note that the minimum distance between two positions in the
//matrix is determined by their Manhattan distance.
//
//Then, if the squirrel were to start at the tree, then the
//minimum total distance required to collect all the nuts is
//2a_1 + ... + 2a_n. However, since the squirrel starts elsewhere,
//we just need to substitute one of the 2a_i terms with a_i + b_i.
//Or equivalently, we replace one of the a_i terms in the sum with
//b_i.
// 2 a_i -> a_i + b_i => min(2 a_i) -> min(a_i + b_i) -> diff(a_i, b_i) a_i - b_i -> max
// Find mosted saved distance, not the closest distance to squerral!
//To minimize the total sum value at the end, we choose i that
//maximizes a_i - b_i.

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        auto manhDist = [](const vector<int>& v1, const vector<int>& v2) {
            return abs(v1[0]-v2[0]) + abs(v1[1]-v2[1]);
        };
        int sum = 0, max_diff = INT_MIN;
        for (auto const & nut : nuts) {
            int a = manhDist(nut, tree), b = manhDist(squirrel, tree);
            sum += 2 * a;
            // Find mosted saved distance, not the closest distance to squerral!
            // Cmp (4, 4) vs (7, 1) => (7, 1) // (a, b)
            max_diff = max(max_diff, a - b);
        }
        return sum - max_diff;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

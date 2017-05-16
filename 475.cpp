// 475. Heaters - https://leetcode.com/problems/heaters

#include "bits/stdc++.h"

using namespace std;

// 1 2 3 4 5 5 5 6 7 9
// In the search for 3, the iterator returned by std::lower_bound
// would refer to 3 and the one from std::upper_bound would refer to 4
// In the search for 5, the iterator returned by std::lower_bound
// would refer to the first 5 and the one from std::upper_bound
// would refer to 6
// In the search for 8, both would refer to 9

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int result = INT_MIN;
        for (const auto &house : houses) {
            int index = lower_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            int dist1 = index - 1 >= 0 ? house - heaters[index - 1] : INT_MAX;
            int dist2 = index < heaters.size() ? heaters[index] - house : INT_MAX;
            result = max(result, min(dist1, dist2));
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
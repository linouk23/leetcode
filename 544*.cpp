// 544. Output Contest Matches - https://leetcode.com/problems/output-contest-matches

#include "bits/stdc++.h"

using namespace std;

// Input: 8
// First round: (1,8),(2,7),(3,6),(4,5)
// Second round: ((1,8),(4,5)),((2,7),(3,6))
// Third round: (((1,8),(4,5)),((2,7),(3,6)))
// Output: (((1,8),(4,5)),((2,7),(3,6)))

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> matches;
        for (int seed = 1; seed <= n; ++seed) {
            matches.emplace_back(to_string(seed));
        }
        
        while ((int)matches.size() != 1){
            vector<string> new_round;
            int n = (int)matches.size();
            for (int idx = 0; idx < n / 2; ++idx) {
                new_round.emplace_back("(" + matches[idx] + "," +
                                       matches[n - idx - 1] + ")");
            }
            matches = new_round;
        }
        return matches.front();
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 649. Dota2 Senate - https://leetcode.com/problems/dota2-senate

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Trick: Each senate R must ban its next closest senate D
// who is from another party, or else D will ban its next
// senate from R's party.
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qr, qd;
        int n = (int)senate.length();
        for (int idx = 0; idx < n; ++idx) {
            if (senate[idx] == 'R') {
                qr.push(idx);
            } else {
                qd.push(idx);
            }
        }
        while (!qr.empty() && !qd.empty()){
            int idxr = qr.front(); qr.pop();
            int idxd = qd.front(); qd.pop();
            // Idxr make the guy at idxd lose his rights
            // in this and all the following rounds.
            if (idxr < idxd) {
                qr.push(idxr + n);
            } else {
                qd.push(idxd + n);
            }
        }
        return (qd.empty()) ? "Radiant" : "Dire";
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ("Radiant", sol.predictPartyVictory("RD"));
    EXPECT_EQ("Dire", sol.predictPartyVictory("RDD"));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

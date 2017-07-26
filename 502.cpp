// 502. IPO - https://leetcode.com/problems/ipo

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Trick: greedy
// pick a list of at most k distinct projects -> multiset
class Solution {
private:
    // Pair<Capital, Profit>
    // (Capital > curCapital)
    // inc order, so we can iterate from the begin
    // to select new k projects that we're able to start
    multiset<pair<int, int>> undoable;
    // Max heap stores profits, so we can choose
    // the most profitable project from a list of
    // available projects (C <= curCapital)
    priority_queue<int> doable;
    void initDS(int avCapital, const vector<int> &Profits, const vector<int> & Capital) {
        for (int idx = 0; idx < (int)Profits.size(); ++idx) {
            pair<int, int> curProject = {Capital[idx], Profits[idx]};
            if (Capital[idx] > avCapital) {
                undoable.insert(curProject);
            } else {
                doable.push(curProject.second);
            }
        }
    }
    void addAvailableProjects(int avCapital) {
        // for (auto it = undoable.begin(); it != undoable.end(); ++it) {
        // Trick:
        // Iterator following the last removed element.
        for (auto it = undoable.begin(); undoable.size(); it = undoable.erase(it)) {
            int capital = it->first;
            if (capital > avCapital) { break; }
            doable.push(it->second);
        }
    }
public:
    int findMaximizedCapital(int k, int W, vector<int> Profits, vector<int> Capital) {
        int avCapital = W;
        int it = 1;
        initDS(avCapital, Profits, Capital);
        while (it++ <= k && !doable.empty()) {
            int mostProfitable = doable.top(); doable.pop();
            avCapital += mostProfitable;
            addAvailableProjects(avCapital);
        }
        return avCapital;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(4, sol.findMaximizedCapital(2, 0, {1,2,3}, {0,1,1}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

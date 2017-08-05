// 358. Rearrange String k Distance Apart - https://leetcode.com/problems/rearrange-string-k-distance-apart

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k == 0) { return str; }
        int letters_left = (int)str.size();
        
        string result;
        unordered_map<char, int> countTable;
        priority_queue<pair<int, char>> max_heap;
        
        for (char ch : str) { countTable[ch]++; }
        for (const auto &p : countTable){
            max_heap.push({p.second, p.first});
        }
        char ch; int count;
        while (!max_heap.empty()){
            vector<pair<int, char>> used; //store used char during one while loop
            int countTable = min(k, letters_left);
            for (int i = 0; i < countTable; i++){
                if (max_heap.empty()) { return ""; }
                tie(count, ch) = max_heap.top(); max_heap.pop();
                result.push_back(ch);
                if (--count > 0) { used.push_back({count, ch}); }
                letters_left--;
            }
            for (const auto &p : used) { max_heap.push(p); }
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ("cbacba", sol.rearrangeString("aabbcc", 3));
    EXPECT_EQ("", sol.rearrangeString("aaabc", 3));
    EXPECT_EQ("acbadcba", sol.rearrangeString("aaadbbcc", 2));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// 364. Nested List Weight Sum II - https://leetcode.com/problems/nested-list-weight-sum-ii

#include "bits/stdc++.h"

using namespace std;


//Different from the previous question where weight is increasing
//from root to leaf, now the weight is defined from bottom up.
//i.e., the leaf level integers have weight 1, and the root
//level integers have the largest weight.
//
//Example 1:
//Given the list [[1,1],2,[1,1]], return 8.
//(four 1's at depth 1, one 2 at depth 2)
//                                           
//Example 2:
//Given the list [1,[4,[6]]], return 17.
//(one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)
// 1 +
// 1 + 4
// 1 + 4 + 6


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// Instead of multiplying by depth, add integers multiple times
// (by going level by level and adding the unweighted sum to
// the weighted sum after each level).
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int level_sum = 0, result = 0;
        while (!nestedList.empty()) {
            vector<NestedInteger> nextLevel;
            for (NestedInteger ni : nestedList) {
                if (ni.isInteger()) { level_sum += ni.getInteger(); }
                else {
                    nextLevel.insert(nextLevel.begin(), ni.getList().begin(), ni.getList().end());
                }
            }
            result += level_sum;
            nestedList = nextLevel;
        }
        return result;
    }
};

// 1 +
// 1 + 4 -> level_sum_i
// 1 + 4 + 6 for [1, [4, [6]]]

// 2 + 1 + 1 + 1 + 1 for [[1,1],2,[1,1]]

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

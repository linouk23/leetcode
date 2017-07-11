// 339. Nested List Weight Sum - https://leetcode.com/problems/nested-list-weight-sum

#include "bits/stdc++.h"

using namespace std;

// Example 1: Given the list [[1,1],2,[1,1]], return 10.
// (Four 1's at depth 2, one 2 at depth 1)
// Example 2: Given the list [1,[4,[6]]], return 27.
// (One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3)


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


// Sum of leaves.

// DFS
//class Solution {
//private:
//    int getSum(const vector<NestedInteger> &vec, int depth) {
//        int result = 0;
//        for (const auto &nstdInt : vec) {
//            // isLeaf()
//            if (nstdInt.isInteger()) {
//                result += nstdInt.getInteger() * depth;
//            } else {
//                result += getSum(nstdInt.getList(), depth + 1);
//            }
//        }
//        return result;
//    }
//public:
//    int depthSum(vector<NestedInteger> & nestedList) {
//        int result = getSum(nestedList, 1);
//        return result;
//    }
//};

// BFS
//class Solution {
//private:
//    queue<pair<NestedInteger, int>> q;
//    void pushAll(const vector<NestedInteger> & nestedList, int level) {
//        for (const auto & nstdInt : nestedList) {
//            q.push({nstdInt, level});
//        }
//    }
//public:
//    int depthSum(vector<NestedInteger> & nestedList) {
//        int level = 1;
//        pushAll(nestedList, level);
//        
//        int result = 0;
//        NestedInteger nstdInt;
//        while (!q.empty()) {
//            tie(nstdInt, level) = q.front(); q.pop();
//            // isLeaf()
//            if (nstdInt.isInteger()) {
//                result += nstdInt.getInteger() * level;
//            } else {
//                pushAll(nstdInt.getList(), level + 1);
//            }
//        }
//        return result;
//    }
//};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

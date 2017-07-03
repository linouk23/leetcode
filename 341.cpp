// 341. Flatten Nested List Iterator - https://leetcode.com/problems/flatten-nested-list-iterator

#include "bits/stdc++.h"

using namespace std;

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

class NestedIterator {
private:
    stack<NestedInteger> st;
    void pushToStack(vector<NestedInteger> &nestedList) {
        for (int idx = (int)nestedList.size() - 1; idx >= 0; --idx) {
            st.push(nestedList[idx]);
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        pushToStack(nestedList);
    }
    
    int next() {
        int value = st.top().getInteger();
        st.pop();
        return value;
    }
    
    bool hasNext() {
        // Invariant: isInt() == true for st.top()
        while (!st.empty() && !st.top().isInteger()) {
            auto list = st.top().getList();
            st.pop();
            pushToStack(list);
        }
        
        return !st.empty();
    }
};


int main() {
    ios::sync_with_stdio(false);
    return 0;
}

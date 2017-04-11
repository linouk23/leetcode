// 225. Implement Stack using Queues - https://leetcode.com/problems/implement-stack-using-queues

#include "bits/stdc++.h"

using namespace std;

class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() { }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for (int index = 0; index < (int)q.size() - 1; ++index) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

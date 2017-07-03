// 287. Find the Duplicate Number - https://leetcode.com/problems/find-the-duplicate-number

#include "bits/stdc++.h"

using namespace std;

// Author: Keith Schwarz (htiek@cs.stanford.edu)
//
// An algorithm for solving the following (classic) hard interview problem:
//
// "You are given an array of integers of length n, where each element ranges
//  from 0 to n - 2, inclusive.  Prove that at least one  duplicate element must
//  exist, and give an O(n)-time, O(1)-space algorithm for finding some
//  duplicated element.  You must not modify the array elements during this
//  process."
//
// This problem (reportedly) took CS legend Don Knuth twenty-four hours to solve
// and I have only met one person (Keith Amling) who could solve it in less time
// than this.
//
// The second part of this problem - finding the duplicated element subject to
// the given constraints - is much harder.  To solve this, we're going to need a
// series of nonobvious insights that transform the problem into an instance of
// something entirely different.
//
// The main trick we need to use to solve this problem is to notice that because
// we have an array of n elements ranging from 0 to n - 2, we can think of the
// array as defining a function f from the set {0, 1, ..., n - 1} onto itself.
// This function is defined by f(i) = A[i].  Given this setup, a duplicated
// value corresponds to a pair of indices i != j such that f(i) = f(j).  Our
// challenge, therefore, is to find this pair (i, j).  Once we have it, we can
// easily find the duplicated value by just picking f(i) = A[i].



// TL;DR: Successor (functional) graphs
// x      : 1 2
// succ(x): 3 5
// edges (1, 3), (2, 5)
// => Floyd’s algorithm
class Solution {
private:
    vector<int> nums_;
    int succ(int x) {
        return nums_[x];
    }
public:
    int findDuplicate(vector<int>& nums) {
        nums_ = nums;
        int x = 0;
        int slow = succ(x);
        int fast = succ(succ(x));
        while (slow != fast) {
            slow = succ(slow);
            fast = succ(succ(fast));
        }
        fast = 0;
        while (slow != fast) {
            slow = succ(slow);
            fast = succ(fast);
        }
        return slow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 56. Merge Intervals - https://leetcode.com/problems/merge-intervals

#include "bits/stdc++.h"

using namespace std;


// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &in1, const Interval &in2) {
            if (in1.start == in2.start) { return in1.end < in2.end; }
            return in1.start < in2.start;
        });
        
        vector<Interval> mergedIntervals;
        if (intervals.empty()) { return mergedIntervals; }
        
        mergedIntervals.emplace_back(intervals.front());
        for (const Interval &interval : intervals) {
            bool shouldCreateNewInterval = mergedIntervals.back().end < interval.start;
            if (shouldCreateNewInterval) {
                mergedIntervals.emplace_back(interval);
            } else {
                mergedIntervals.back().end = max(mergedIntervals.back().end, interval.end);
            }
        }
        return mergedIntervals;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

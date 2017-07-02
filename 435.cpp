// 435. Non-overlapping Intervals - https://leetcode.com/problems/non-overlapping-intervals

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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()) { return 0; }
        sort(intervals.begin(), intervals.end(),
             [](const Interval& i1, const Interval& i2) {
                 return i1.end < i2.end;
             });
        int result = 1;
        auto cur_interval = intervals.front();
        for (const auto &interval : intervals) {
            if (interval.start >= cur_interval.end) {
                ++result;
                cur_interval = interval;
            }
        }
        return (int)intervals.size() - result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

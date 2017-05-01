// 57. Insert Interval - https://leetcode.com/problems/insert-interval

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int n = (int)intervals.size();
        int index = 0;
        while (index < n && intervals[index].end < newInterval.start) {
            result.emplace_back(intervals[index++]);
        }
        while (index < n && newInterval.end >= intervals[index].start) {
            newInterval.start = min(newInterval.start, intervals[index].start);
            newInterval.end = max(newInterval.end, intervals[index++].end);
        }
        result.emplace_back(newInterval);
        while (index < n) {
            result.emplace_back(intervals[index++]);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

// 252. Meeting Rooms - https://leetcode.com/problems/meeting-rooms

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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const Interval& x, const Interval& y) { return x.start < y.start; });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i - 1].end > intervals[i].start) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

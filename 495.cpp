// 495. Teemo Attacking - https://leetcode.com/problems/teemo-attacking

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    struct Interval {
        int start, finish;
    };
    vector<Interval> mergeIntervals(vector<Interval>& intervals) {
        vector<Interval> result;
        for (Interval &interval : intervals) {
            if (result.empty() || result.back().finish < interval.start) {
                result.push_back(interval);
            } else {
                result.back().finish = max(result.back().finish,
                                           interval.finish
                                           );
            }
        }
        return result;
    }
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        vector<Interval> intervals;
        for (int num : timeSeries) {
            intervals.push_back({num, num + duration - 1});
        }
        intervals = mergeIntervals(intervals);
        int result = 0;
        for (const Interval& interval : intervals) {
            result += interval.finish - interval.start + 1;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

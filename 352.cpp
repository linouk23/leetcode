// 352. Data Stream as Disjoint Intervals - https://leetcode.com/problems/data-stream-as-disjoint-intervals

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;


// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// If you have multiple elements in the range [first, last)
// whose value equals the value val you are searching for,
// then the range [l, u) where
// l = std::lower_bound(first, last, val)
// u = std::upper_bound(first, last, val)
class SummaryRanges {
private:
    vector<Interval> ints;
    int bs(int val) {
        int L = -1;
        int R = (int)ints.size();
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (ints[M].end >= val) {
                R = M;
            } else {
                L = M;
            }
        }
        return R;
    }
    void merge(int idx) {
        int n = (int)ints.size();
        if (n <= 1) { return; }
        idx = max(0, idx);
        int start = idx;
        auto interval = ints[idx++];
        for (; idx < n; ++idx) {
            if (ints[idx].start - interval.end <= 1) {
                interval.end = max(interval.end, ints[idx].end);
            } else {
                break;
            }
        }
        idx -= 1;
        ints[start] = interval;
        int offset = 1;
        for (; idx + offset < n; ++offset) {
            ints[start + offset] = ints[idx + offset];
        }
        ints.erase(ints.begin() + start + offset, ints.end());
    }
public:
    SummaryRanges() { }
    
    void addNum(int val) {
        int pos = bs(val);
        // int.end >= pos
        int n = (int)ints.size();
        if (pos == n) {
            ints.push_back({val, val});
            merge(pos - 1);
            return;
        }
        if (ints[pos].start <= val) { return; }
        ints.insert(ints.begin() + pos, {val, val});
        if (ints[pos - 1].end + 1 >= ints[pos].start) {
            merge(pos - 1);
        } else {
            merge(pos);
        }
    }
    
    vector<Interval> getIntervals() {
        return ints;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

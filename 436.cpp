// 436. Find Right Interval - https://leetcode.com/problems/find-right-interval

#include "bits/stdc++.h"

using namespace std;


// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool operator<(const Interval &i, const Interval &that) {
    if (i.start == that.start) {
        return i.end < that.end;
    }
    return i.start < that.start;
}

bool operator==(const Interval &i, const Interval &that) {
    return i.start == that.start && i.end == that.end;
}

namespace std {
    template <>
    struct hash<Interval> {
        size_t operator () (const Interval &o) const {
            return (std::hash<int>()(o.start) << 1) ^ std::hash<int>()(o.end);
        }
    };
}

class Solution {
private:
    bool is_match(const Interval &i1, const Interval &i2) {
        return i2.start >= i1.end;
    }
    int bin_search(const Interval &interval, vector<Interval>& intervals) {
        int L = -1;
        int R = (int)intervals.size();
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (is_match(interval, intervals[M])) {
                R = M;
            } else {
                L = M;
            }
        }
        return R;
    }
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        unordered_map<Interval, int> in_to_idx;
        unordered_map<int, Interval> idx_to_in;
        int n = (int)intervals.size();
        for (int idx = 0; idx < n; ++idx) {
            in_to_idx[intervals[idx]] = idx;
            idx_to_in[idx] = intervals[idx];
        }
        sort(intervals.begin(), intervals.end());
        vector<int> result;
        for (int idx = 0; idx < n; ++idx) {
            int pos = bin_search(idx_to_in[idx], intervals);
            if (pos == n) {
                result.emplace_back(-1);
            } else {
                result.emplace_back(in_to_idx[intervals[pos]]);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

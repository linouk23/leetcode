// 149. Max Points on a Line - https://leetcode.com/problems/max-points-on-a-line

#include "bits/stdc++.h"

using namespace std;

// Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

const int INF = (int) 1e9;

bool same(const Point &p1, const Point &p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

int getGCD(int a, int b) {
    if (b == 0) { return a; }
    return getGCD(b, a % b);
}

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.empty()) { return 0; }
        int n = (int)points.size();
        int result = 1;
        for (int idx1 = 0; idx1 < n; ++idx1) {
            // coef. a -> count
            unordered_map<int, unordered_map<int, int>> hashtable;
            Point base = points[idx1];
            int num_of_base = 0;
            for (int idx2 = 0; idx2 < n; ++idx2) {
                Point theOther = points[idx2];
                // y = ax + b
                
                int diff_x = base.x - theOther.x;
                int diff_y = base.y - theOther.y;
                int gcd = getGCD(diff_x, diff_y);
                if (gcd) {
                    diff_x /= gcd;
                    diff_y /= gcd;
                }
                if (same(base, theOther)) { num_of_base += 1; continue; }
                // Vertical line
                if (diff_x == 0) {
                    hashtable[INF][INF] += 1;
                } else {
                    hashtable[diff_x][diff_y] += 1;
                }
            }
            int max_for_base = num_of_base;
            for (const auto &p1 : hashtable) {
                for (const auto &p2 : p1.second)
                if (p2.second + num_of_base > max_for_base) {
                    max_for_base = p2.second + num_of_base;
                }
            }
            result = max(result, max_for_base);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

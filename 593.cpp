// 593. Valid Square - https://leetcode.com/problems/valid-square

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int d(vector<int>& p1, vector<int>& p2) {
        return int(pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2));
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s({ d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4) });
        return !s.count(0) && int(s.size()) == 2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

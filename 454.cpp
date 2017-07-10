// 454. 4Sum II - https://leetcode.com/problems/4sum-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    void generate_pairs(unordered_map<int, int>& to, const vector<int>& from1, const vector<int>& from2) {
        int n = (int)from1.size();
        for (int idx1 = 0; idx1 < n; ++idx1) {
            for (int idx2 = 0; idx2 < n; ++idx2) {
                to[from1[idx1] + from2[idx2]] += 1;
            }
        }
    }
public:
    int fourSumCount(vector<int> A, vector<int> B, vector<int> C, vector<int> D) {
        unordered_map<int, int> map1, map2;
        
        generate_pairs(map1, A, B);
        generate_pairs(map2, C, D);
        int result = 0;
        for (const auto &p : map1) {
            if (!map2.count(-p.first)) { continue; }
            result += p.second * map2[-p.first];
        }
        return result;
    }
};


int main() {
    ios::sync_with_stdio(false);
    return 0;
}

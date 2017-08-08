// 77. Combinations - https://leetcode.com/problems/combinations

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    vector<vector<int> > result;
    int n_, k_;
    void helper(vector<int> comb, deque<bool> used, int last_used_num) {
        if ((int)comb.size() == k_) {
            result.emplace_back(comb);
            return;
        }
        
        for (int num = last_used_num + 1; num <= n_; ++num) {
            if (used[num]) { continue; }
            used[num] = true;
            comb.emplace_back(num);
            
            helper(comb, used, num);
            
            used[num] = false;
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        n_ = n;
        k_ = k;
        deque<bool> used(n + 1, false);
        helper({}, used, 0);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

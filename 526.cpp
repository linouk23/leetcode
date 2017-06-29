// 526. Beautiful Arrangement - https://leetcode.com/problems/beautiful-arrangement

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n;
    int result = 0;
    void helper(vector<int> permutation, vector<bool> used) {
        if (permutation.size() == n) {
            ++result;
            return;
        }
        for (int num = 1; num <= n; ++num) {
            if (used[num]) { continue; }
            
            if (num % (permutation.size() + 1) != 0 &&
                (permutation.size() + 1) % num != 0) {
                continue;
            }
            
            used[num] = true;
            permutation.push_back(num);
            helper(permutation, used);
            used[num] = false;
            permutation.pop_back();
        }
    }
public:
    int countArrangement(int N) {
        n = N;
        vector<bool> used(N + 1, false);
        helper({}, used);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

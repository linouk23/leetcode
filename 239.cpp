// 239. Sliding Window Maximum - https://leetcode.com/problems/sliding-window-maximum

#include "bits/stdc++.h"

using namespace std;

struct Pair {
    int value, pos;
};

class Solution {
private:
    void sieve_push(deque<Pair> &dq, int k, const vector<int> &nums, int idx) {
        while (!dq.empty() && dq.front().value < nums[idx]) {
            dq.pop_front();
        }
        dq.push_front({nums[idx], idx});
    }
    void clean_old(deque<Pair> &dq, int k, const vector<int> &nums, int idx) {
        if (idx - dq.back().pos >= k) {
            dq.pop_back();
        }
    }
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<Pair> dq;
        if (nums.empty()) { return {}; }
        
        for (int idx = 0; idx < k; ++idx) {
            // Trick.
            sieve_push(dq, k, nums, idx);
        }
        
        vector<int> result;
        result.push_back(dq.back().value);
        for (int idx = k; idx < (int)nums.size(); ++idx) {
            clean_old(dq, k, nums, idx);
            sieve_push(dq, k, nums, idx);
            result.push_back(dq.back().value);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

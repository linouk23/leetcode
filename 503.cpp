// 503. Next Greater Element II - https://leetcode.com/problems/next-greater-element-ii

#include "bits/stdc++.h"

using namespace std;

// Trick.
// Next Greater Element/Max in the array: think about stack/deque.
// Maybe store pairs: (ind, val).
// De'Aaron Fox == new element pushed to stack.
// Use a stack to keep a decreasing subsequence.
// [5, 4, 1] + 6 => [6], table[5] = table[4] = table[1] = 6.

struct Pair {
    int idx, val;
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> nums) {
        int n = (int)nums.size();
        vector<int> result(n, -1);
        // Trick.
        // Don't create 2 * n vector.
        // circ_nums.insert(circ_nums.end(), nums.begin(), nums.end());
        
        stack<Pair> st;
        for (int idx = 0; idx < 2 * n; ++idx) {
            int idx_mod = idx % n;
            int num = nums[idx_mod];
            while (!st.empty() && st.top().val < num) {
                int key = st.top().idx; st.pop();
                result[key] = num;
            }
            st.push({idx_mod, num});
        }
        return result;
    }
};



int main() {
    ios::sync_with_stdio(false);
    return 0;
}

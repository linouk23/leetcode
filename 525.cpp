// 525. Contiguous Array - https://leetcode.com/problems/contiguous-array

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
//        \
//         \  /\
//          \/  \  /
//               \/
        // value - the 1st index
        unordered_map<int, int> hashtable;
        int result = 0;
        int value = 0;
        hashtable[0] = -1;
        for (int idx = 0; idx < (int)nums.size(); ++idx) {
            if (nums[idx] == 1) { value += 1;}
            else { value -= 1; }
            if (!hashtable.count(value)) {
                hashtable[value] = idx;
            } else {
                result = max(result, idx - hashtable[value]);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

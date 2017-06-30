// 594. Longest Harmonious Subsequence - https://leetcode.com/problems/longest-harmonious-subsequence

#include "bits/stdc++.h"

using namespace std;

const int INF = (int)1e9;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> hashtable;
        for (int num : nums) {
            hashtable[num] += 1;
        }
        int result = 0;
        for (int num : nums) {
            if (hashtable.count(num + 1)) {
                result = max(result, hashtable[num] + hashtable[num + 1]);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

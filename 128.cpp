// 128. Longest Consecutive Sequence - https://leetcode.com/problems/longest-consecutive-sequence

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> hashmap;
        for (int num : nums) {
            hashmap[num] = false;
        }
        int result = 0;
        for (auto it : hashmap) {
            if (it.second) { continue; }
            int ans = 1;
            int num = it.first;
            int step = 1;
            while (hashmap.count(num - step)) {
                ++ans;
                hashmap[num - step++] = true;
            }
            step = 1;
            while (hashmap.count(num + step)) {
                ++ans;
                hashmap[num + step++] = true;
            }
            result = max(result, ans);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

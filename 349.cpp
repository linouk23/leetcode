// 349. Intersection of Two Arrays - https://leetcode.com/problems/intersection-of-two-arrays

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashset(nums1.begin(), nums1.end());

        vector<int> answer;
        for (int num : nums2) {
            if (hashset.count(num)) {
                answer.emplace_back(num);
                hashset.erase(num);
            }
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input_fst = {1, 2, 2, 1};
    vector<int> input_snd = {2, 2};
    vector<int> expected_ans = {2};
    assert(solution.intersection(input_fst, input_snd) == expected_ans);

    return 0;
}

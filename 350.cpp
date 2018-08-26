// 350. Intersection of Two Arrays II - https://leetcode.com/problems/intersection-of-two-arrays-ii

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> numberToCount;
        for (int number : nums1) {
            numberToCount[number] += 1;
        }
        
        vector<int> intersection;
        for (int number : nums2) {
            if (numberToCount.count(number)) {
                intersection.emplace_back(number);
                --numberToCount[number];
                if (numberToCount[number] == 0) {
                    numberToCount.erase(number);
                }
            }
        }
        return intersection;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input_fst = {1, 2, 2, 1};
    vector<int> input_snd = {2, 2};
    vector<int> expected_ans = {2, 2};
    assert(solution.intersect(input_fst, input_snd) == expected_ans);

    input_fst = {1};
    input_snd = {1, 1};
    expected_ans = {1};
    assert(solution.intersect(input_fst, input_snd) == expected_ans);

    return 0;
}
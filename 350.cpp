// 350. Intersection of Two Arrays II - https://leetcode.com/problems/intersection-of-two-arrays-ii

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashtable;
        for (int num : nums1) {
            hashtable[num] += 1;
        }

        vector<int> answer;
        for (int num : nums2) {
            if (hashtable.count(num) && hashtable[num]) {
                hashtable[num] -= 1;
                answer.emplace_back(num);
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
    vector<int> expected_ans = {2, 2};
    assert(solution.intersect(input_fst, input_snd) == expected_ans);

    input_fst = {1};
    input_snd = {1, 1};
    expected_ans = {1};
    assert(solution.intersect(input_fst, input_snd) == expected_ans);

    return 0;
}
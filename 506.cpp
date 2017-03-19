// 506. Relative Ranks - https://leetcode.com/problems/relative-ranks

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int, int>> sportsmen;
        for (int index = 0; index < (int)nums.size(); ++index) {
            sportsmen.emplace_back(nums[index], index);
        }

        sort(sportsmen.rbegin(), sportsmen.rend());
        vector<string> answer((int)nums.size());
        for (int index = 0; index < (int)sportsmen.size(); ++index){
            if (index == 0) {
                answer[sportsmen[index].second] = "Gold Medal";
            } else if (index == 1) {
                answer[sportsmen[index].second] = "Silver Medal";
            } else if (index == 2) {
                answer[sportsmen[index].second] = "Bronze Medal";
            } else {
                answer[sportsmen[index].second] = to_string(index + 1);
            }
        }

        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {5, 4, 3, 2, 1};
    vector<string> expected_ans = {"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"};
    assert(solution.findRelativeRanks(input) == expected_ans);

    input = {5, 4};
    expected_ans = {"Gold Medal", "Silver Medal"};
    assert(solution.findRelativeRanks(input) == expected_ans);

    return 0;
}

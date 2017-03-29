// 217. Contains Duplicate - https://leetcode.com/problems/contains-duplicate

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (int num : nums) {
            if (hashset.count(num)) {
                return true;
            }
            hashset.insert(num);
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {1, 2, 3, 4, 1};
    assert(solution.containsDuplicate(input) == true);

    input = {1, 2, 3};
    assert(solution.containsDuplicate(input) == false);

    input = {};
    assert(solution.containsDuplicate(input) == false);

    return 0;
}

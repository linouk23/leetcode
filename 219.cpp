// 219. Contains Duplicate II - https://leetcode.com/problems/contains-duplicate-ii

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hashset;

        for (int index = 0; index < (int)nums.size(); ++index) {
            if (index > k) {
                hashset.erase(nums[index - k - 1]);
            }

            if (hashset.count(nums[index])) {
                return true;
            }
            hashset.insert(nums[index]);
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {1, 2, 3, 4, 1};
    assert(solution.containsNearbyDuplicate(input, 4) == true);

    input = {1, 2, 3, 4, 1};
    assert(solution.containsNearbyDuplicate(input, 3) == false);

    input = {1, 2, 3};
    assert(solution.containsNearbyDuplicate(input, 1) == false);

    input = {};
    assert(solution.containsNearbyDuplicate(input, 3) == false);

    return 0;
}

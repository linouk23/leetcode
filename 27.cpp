// 27. Remove Element - https://leetcode.com/problems/remove-element

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index_to_write = 0;
        for (int index = 0; index < (int)nums.size(); ++index) {
            if (nums[index] != val) {
                nums[index_to_write++] = nums[index];
            }
        }

        return index_to_write;   
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {3, 2, 2, 3};
    assert(solution.removeElement(input, 3) == 2);

    return 0;
}

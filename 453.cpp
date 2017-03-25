// 453. Minimum Moves to Equal Array Elements - https://leetcode.com/problems/minimum-moves-to-equal-array-elements

#include <bits/stdc++.h>

using namespace std;

// Adding 1 to n - 1 elements is the same as subtracting 1 from one element,
// w.r.t goal of making the elements in the array equal.
// So, best way to do this is make all the elements in the array equal to the min element.
// sum(array) - n * min_element

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_elem = INT_MAX;
        for (int num : nums) {
            min_elem = min(min_elem, num);
        }

        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        int n = (int)nums.size();
        return sum - n * min_elem;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {1, 2, 3};
    assert(solution.minMoves(input) == 3);

    return 0;
}

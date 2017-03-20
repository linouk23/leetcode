// 11. Container With Most Water - https://leetcode.com/problems/container-with-most-water

#include <bits/stdc++.h>

using namespace std;

// O(n): 2 pointers.
// Proved by contradiction:

// Suppose the returned result is not the optimal solution. Then there must exist an optimal solution,
// say a container with a_L and a_R (left and right respectively), such that it has a greater volume
// than the one we got. Since our algorithm stops only if the two pointers meet.
// So, we must have visited one of them but not the other. WLOG, let's say we visited a_L but not a_R. 
// When a pointer stops at a_L, it won't move until:

// 1) The other pointer also points to a_L.
// In this case, iteration ends. But the other pointer must have visited a_R on its way from right end
// to a_L. Contradiction to our assumption that we didn't visit a_R.

// 2) The other pointer arrives at a value, say a_RR, that is greater than a_L before it reaches a_R.
// In this case, we does move a_L. But notice that the volume of a_L and a_RR is already greater than 
// a_L and a_R (as it is wider and heigher), which means that a_L and a_R is not the optimal
// solution -- Contradiction!

// Both cases arrive at a contradiction.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0;
        int R = (int)height.size() - 1;
        int max_area = 0;
        while(L < R) {
            max_area = max(max_area, min(height[R], height[L]) * (R - L));
            if (height[L] < height[R]) {
                ++L;
            } else {
                --R;
            }
        }
        return max_area;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input = {2, 2};
    assert(solution.maxArea(input) == 2);

    input = {3, 4};
    assert(solution.maxArea(input) == 3);

    input = {2, 1};
    assert(solution.maxArea(input) == 1);

    input = {2, 1, 3};
    assert(solution.maxArea(input) == 4);
    
    return 0;
}

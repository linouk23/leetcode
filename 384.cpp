// 384. Shuffle an Array - https://leetcode.com/problems/shuffle-an-array

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        reset_nums_ = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return reset_nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto nums_ = reset_nums_;
        int n = (int)nums_.size();
        random_device rd;
        mt19937 gen(rd());
        for (int index = 0; index < n; ++index) {
            uniform_int_distribution<> dis(index, n - 1);
            int selected_index = dis(gen);
            swap(nums_[index], nums_[selected_index]);
        }
        return nums_;
    }
private:
    vector<int> reset_nums_;
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

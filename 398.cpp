// 398. Random Pick Index - https://leetcode.com/problems/random-pick-index

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    vector<int> nums;
    default_random_engine generator;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        uniform_real_distribution<double> distribution(0.0, 1.0);
        double break_point, rand_num;
        
        int num_of_targets_so_far = 0, result = -1, num;
        for (int index = 0; index < (int)nums.size(); ++index) {
            num = nums[index];
            if (num != target) { continue; }
            
            ++num_of_targets_so_far;
            break_point = 1.0 / ((double)num_of_targets_so_far);
            rand_num = distribution(generator);
            if (rand_num <= break_point) {
                result = index;
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

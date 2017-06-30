// 605. Can Place Flowers - https://leetcode.com/problems/can-place-flowers

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    vector<int> _flowerbed;
    int _n;
    bool is_one(int index) {
        return _flowerbed[index] == 1;
    }
    bool has_adj_one(int index) {
        if (index == 0) { return _flowerbed[index + 1] == 1; }
        if (index == _n - 1) { return _flowerbed[index - 1] == 1; }
        return _flowerbed[index - 1] || _flowerbed[index + 1];
    }
public:
    bool canPlaceFlowers(vector<int> flowerbed, int n) {
        vector<int> flowers(flowerbed.size(), 0);
        _flowerbed = flowerbed;
        _n = (int)flowerbed.size();
        if (_n == 1) {
            return (1 - flowerbed[0]) >= n;
        }
        
        for (size_t idx = 0; idx < flowerbed.size(); ++idx) {
            if (is_one(int(idx)) || has_adj_one(int(idx))) {
                flowers[idx] = 1;
            }
        }
        int num_of_conseq_zeroes = 0;
        int result = 0;
        for (int flower : flowers) {
            if (flower == 0) {
                ++num_of_conseq_zeroes;
            } else {
                result += ceil(double(num_of_conseq_zeroes) / 2.0);
                num_of_conseq_zeroes = 0;
            }
        }
        result += ceil(double(num_of_conseq_zeroes) / 2.0);
        return result >= n;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

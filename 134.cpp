// 134. Gas Station - https://leetcode.com/problems/gas-station

#include "bits/stdc++.h"

using namespace std;

const int INF = (int)1e9;

class Solution {
private:
    struct Result {
        int idx, value;
    };
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();
        int gas_left = gas[0];
        // idx, value
        Result min_city = {0, INF};
        // 1...n - 1, 0
        for (int idx = 0; idx < n; ++idx) {
            gas_left -= cost[idx];
            if (gas_left < min_city.value) {
                min_city = {(idx + 1) % n, gas_left};
            }
            gas_left += gas[(idx + 1) % n];
        }
        gas_left = gas[min_city.idx];
        for (int count = 0; count < n; ++count) {
            gas_left -= cost[(min_city.idx + count) % n];
            if (gas_left < 0) {
                return -1;
            }
            gas_left += gas[(min_city.idx + count + 1) % n];
        }
        return min_city.idx;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

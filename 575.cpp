// 575. Distribute Candies - https://leetcode.com/problems/distribute-candies

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> kinds;
        for (int kind : candies) {
            kinds.insert(kind);
        }
        return min((int)kinds.size(), (int)candies.size() / 2);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

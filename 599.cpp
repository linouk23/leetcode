// 599. Minimum Index Sum of Two Lists - https://leetcode.com/problems/minimum-index-sum-of-two-lists

#include "bits/stdc++.h"

using namespace std;

const int INF = (int)1e9;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, pair<int, int> > hashtable;
        
        struct Result {
            int min_sum;
            vector<string> words;
        };
        
        Result result {INF, {}};
        
        for (int idx = 0; idx < (int)list1.size(); ++idx) {
            hashtable[list1[idx]] = {idx, INF};
        }
        
        for (int idx = 0; idx < (int)list2.size(); ++idx) {
            if (!hashtable.count(list2[idx])) { continue; }
            hashtable[list2[idx]].second = idx;
            auto p = hashtable[list2[idx]];
            if (p.first + p.second < result.min_sum) {
                result.min_sum = p.first + p.second;
                result.words = { list2[idx] };
            } else if (p.first + p.second == result.min_sum) {
                result.words.emplace_back(list2[idx]);
            }
        }
        return result.words;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

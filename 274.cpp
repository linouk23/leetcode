// 274. H-Index - https://leetcode.com/problems/h-index

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = (int)citations.size();
        vector<int> buckets(n + 1, 0);
        for (int index = 0; index < n; ++index) {
            int citation = citations[index];
            if (citation >= n) {
                buckets[n] += 1;
            } else {
                buckets[citation] += 1;
            }
        }
        int sum = 0;
        for (int answer = n; answer >= 0; --answer) {
            sum += buckets[answer];
            if (sum >= answer) {
                return answer;
            }
        }
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

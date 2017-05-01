// 373. Find K Pairs with Smallest Sums - https://leetcode.com/problems/find-k-pairs-with-smallest-sums

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<long long> fnums1, fnums2;
        int n = (int)nums1.size();
        int m = (int)nums2.size();
        k = min(k, n * m);
        vector<pair<int, int>> result;
        const long long INF = 1e15;
        if (k == 0) { return result; }
        for (int i = 0; i < k + 1; ++i) {
            if (i < nums1.size()) {
                fnums1.emplace_back(nums1[i]);
            } else {
                fnums1.emplace_back(INF);
            }
            
            if (i < nums2.size()) {
                fnums2.emplace_back(nums2[i]);
            } else {
                fnums2.emplace_back(INF);
            }
        }
        
        auto sum = [&fnums1, &fnums2](int row, int column) -> long long { return fnums1[row] + fnums2[column]; };
        
        min_heap_.emplace(HeapVertex{sum(0, 0), 0, 0});
        
        auto get_right = [&sum](const HeapVertex & v) -> HeapVertex { return HeapVertex{sum(v.row, v.column + 1), v.row, v.column + 1}; };
        auto get_next_fst = [&sum](const HeapVertex & v) -> HeapVertex { return HeapVertex{sum(v.row + 1, 0), v.row + 1, 0}; };
        
        for (int index = 0; index < k; ++index) {
            auto top = min_heap_.top(); min_heap_.pop();
            result.emplace_back(fnums1[top.row], fnums2[top.column]);
            if (index == k - 1) { continue; }
            min_heap_.emplace(get_right(top));
            if (top.column == 0) {
                min_heap_.emplace(get_next_fst(top));
            }
        }
        return result;
    }

private:
    struct HeapVertex {
        long long value;
        int row, column;
        
        bool operator>(const HeapVertex& that) const {
            return value > that.value;
        }
    };
    priority_queue<HeapVertex, vector<HeapVertex>, greater<HeapVertex>> min_heap_;
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

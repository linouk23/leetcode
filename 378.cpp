// 378. Kth Smallest Element in a Sorted Matrix - https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        min_heap_.emplace(HeapVertex{matrix[0][0], 0, 0});
        
        auto get_right = [&matrix](const HeapVertex & v) -> HeapVertex { return HeapVertex{matrix[v.row][v.column + 1], v.row, v.column + 1}; };
        auto get_next_fst = [&matrix](const HeapVertex & v) -> HeapVertex { return HeapVertex{matrix[v.row + 1][0], v.row + 1, 0}; };
        int result = -1;
        int m = (int)matrix[0].size();
        int n = (int)matrix.size();
        for (int index = 0; index < k; ++index) {
            auto top = min_heap_.top(); min_heap_.pop();
            if (index == k - 1) {
                result = top.value;
                continue;
            }
            if (top.column < m - 1) {
                min_heap_.emplace(get_right(top));
            }
            if (top.column == 0 && top.row < n - 1) {
                min_heap_.emplace(get_next_fst(top));
            }
        }
        return result;
    }

private:
    struct HeapVertex {
        int value, row, column;
        
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

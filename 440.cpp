// 440. K-th Smallest in Lexicographical Order

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;
        while (k > 0) {
            // subtree size (vals <= n) + 1 (1 is for 'cur + 1' node)
            long long steps_to_reach_neighbour = calculate_nodes_between(n, cur, cur + 1);
            if ((long long)k >= steps_to_reach_neighbour) {
                // Jump over subtree.
                cur += 1;
                k -= steps_to_reach_neighbour;
            } else {
                // Jump to the next node in preorder traversal
                cur *= 10;
                k -= 1;
            }
        }
        return cur;
    }
    
    long long calculate_nodes_between(int n, long long start, long long neighbour) {
        long long steps_to_get_to_neighbour = 0;
        while (start <= n) {
            if (n >= neighbour) {
                // 10, 11, ..., 19; 20 = neighbour => 10 nodes from level & subtree
                steps_to_get_to_neighbour += neighbour - start;
            } else {
                // 10, 11, 12, 13 = n, ...; 20 = neighbour => 4 nodes from level & subtree
                steps_to_get_to_neighbour += (n - start) + 1;
            }
            start *= 10;
            neighbour *= 10;
        }
        return steps_to_get_to_neighbour;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

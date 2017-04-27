// 96. Unique Binary Search Trees - https://leetcode.com/problems/unique-binary-search-trees

#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(max(3, n + 1), 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int tree_size = 3; tree_size <= n; ++tree_size) {
            int result = 0;
            // Let's try to use every node as a root.
            for (int root = 1; root <= tree_size; ++root) {
                // Sequence of 1...root - 1 in the left subtree.
                // We've got the same task for the smaller n = root - 1.
                int num_of_left_subtrees = dp[root - 1];
                
                // Sequence of root + 1...tree_size in the right subtree.
                // We've got the same task for the smaller n = tree_size - root.
                int num_of_right_subtrees = dp[tree_size - root];
                
                result += num_of_left_subtrees * num_of_right_subtrees;
            }
            dp[tree_size] = result;
        }
        return dp[n];
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

// 563. Binary Tree Tilt - https://leetcode.com/problems/binary-tree-tilt

#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int result = 0;
public:
    int post_sum(TreeNode* node) {
        if (node == nullptr) { return 0; }
        int left_tree_sum = post_sum(node->left);
        int right_tree_sum = post_sum(node->right);
        result += abs(right_tree_sum - left_tree_sum);
        return node->val + left_tree_sum + right_tree_sum;
    }
    
    int findTilt(TreeNode* root) {
        post_sum(root);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

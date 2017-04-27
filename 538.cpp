// 538. Convert BST to Greater Tree - https://leetcode.com/problems/convert-bst-to-greater-tree

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
private:
    int total_sum_so_far = 0;
public:
    void inorder(TreeNode* node) {
        if (node == nullptr) { return; }
        inorder(node->right);
        total_sum_so_far += node->val;
        node->val += total_sum_so_far - node->val;
        inorder(node->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        return root;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

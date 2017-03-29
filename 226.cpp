// 226. Invert Binary Tree - https://leetcode.com/problems/invert-binary-tree

#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper(TreeNode* root) {
        if (root == nullptr) {
            return;
        } 
        swap(root->left, root->right);
        helper(root->left);
        helper(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

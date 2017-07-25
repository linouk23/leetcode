// 156. Binary Tree Upside Down - https://leetcode.com/problems/binary-tree-upside-down

// Idea: postorder.
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left) return root;

        TreeNode* cleft = root->left;
        TreeNode* cright = root->right;

        // So we'll be able to return this leaf.
        TreeNode* new_root = upsideDownBinaryTree(root->left);

        cleft->right = root;
        cleft->left = cright;
        
        // Trick.
        root->left = nullptr;
        root->right = nullptr;
        return new_root;
    }
};
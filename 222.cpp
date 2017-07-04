// 222. Count Complete Tree Nodes - https://leetcode.com/problems/count-complete-tree-nodes

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
    int height(TreeNode* node, bool is_left) {
        if (node == nullptr) { return 0; }
        return 1 + height(is_left ? node->left : node->right, is_left);
    }
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) { return 0; }
        int l_height = height(root->left, true);
        int r_height = height(root->left, false);
        if (l_height != r_height) {
            return (1 << r_height) + countNodes(root->left);
        } else {
            return (1 << r_height) + countNodes(root->right);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

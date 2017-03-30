// 111. Minimum Depth of Binary Tree - https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    int depth(TreeNode* root) {
        if (root == nullptr) { return 0; }
        if (!root->left && !root->right) { return 1; }
        if (root->left && root->right) {
            return min(depth(root->left), depth(root->right)) + 1;
        }
        if (root->left)  { return depth(root->left) + 1; }
        if (root->right) { return depth(root->right) + 1; }
    }
    int minDepth(TreeNode* root) {
        return depth(root);
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

// 114. Flatten Binary Tree to Linked List - https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    TreeNode* prev = nullptr;
public:
    void postorder(TreeNode* node) {
        if (node == nullptr) { return; }
        postorder(node->right);
        postorder(node->left);
        node->right = prev;
        node->left = nullptr;
        prev = node;
    }
    
    void flatten(TreeNode* root) {
        postorder(root);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

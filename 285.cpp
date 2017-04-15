// 285. Inorder Successor in BST - https://leetcode.com/problems/inorder-successor-in-bst

#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succ = nullptr;
        while(root != nullptr) {
            if (p->val < root->val) {
                succ = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return succ;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

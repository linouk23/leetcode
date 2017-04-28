// 99. Recover Binary Search Tree - https://leetcode.com/problems/recover-binary-search-tree

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
    TreeNode *fst_elem = nullptr,
             *snd_elem = nullptr,
             *prev = nullptr;
public:
    void inorder(TreeNode* node) {
        if (node == nullptr) { return; }
        inorder(node->left);
        
        if (prev && prev->val > node->val) {
            if (!fst_elem) {
                fst_elem = prev;
            }
            snd_elem = node;
        }
        
        prev = node;
        inorder(node->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp = fst_elem->val;
        fst_elem->val = snd_elem->val;
        snd_elem->val = temp;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

// 623. Add One Row to Tree - https://leetcode.com/problems/add-one-row-to-tree

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
    void preorder(TreeNode* node, int level, int v, int d) {
        if (node == nullptr) { return; }
        if (level == d - 1) {
            if (node->left) {
                auto temp = new TreeNode(v);
                temp->left = node->left;
                node->left = temp;
            } else {
                node->left = new TreeNode(v);
            }
            
            if (node->right) {
                auto temp = new TreeNode(v);
                temp->right = node->right;
                node->right = temp;
            } else {
                node->right = new TreeNode(v);
            }
            
            return;
        }
        preorder(node->left , level + 1, v, d);
        preorder(node->right, level + 1, v, d);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            auto temp = new TreeNode(v);
            temp->left = root;
            return temp;
        }
        preorder(root, 0, v, d - 1);
        return root;
    }
};

int main() {
    ios::sync_with_stdio(false);
    Solution sol;
    cout << sol.countArrangement(4);
    return 0;
}

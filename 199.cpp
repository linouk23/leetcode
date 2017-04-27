// 199. Binary Tree Right Side View - https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> result;
public:
    void preorder(TreeNode* node, int level) {
        if (node == nullptr) { return; }
        if (result.size() <= level) {
            result.emplace_back(node->val);
        }
        preorder(node->right, level + 1);
        preorder(node->left, level + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        preorder(root, 0);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

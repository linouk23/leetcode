// 545. Boundary of Binary Tree - https://leetcode.com/problems/boundary-of-binary-tree

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        if (root->left || root->right) res.emplace_back(root->val);
        leftBoundary(root->left, res);
        preorder(root, res);
        rightBoundary(root->right, res);
        return res;
    }
private:
    void leftBoundary(TreeNode* node, vector<int>& res) {
        if (!node || (!node->left && !node->right)) return;
        res.emplace_back(node->val);
        if (!node->left) leftBoundary(node->right, res);
        else leftBoundary(node->left, res);
    }
    void rightBoundary(TreeNode* node, vector<int>& res) {
        if (!node || (!node->left && !node->right)) return;
        if (!node->right) rightBoundary(node->left, res);
        else rightBoundary(node->right, res);
        res.emplace_back(node->val);
    }
    void preorder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        if (!node->left && !node->right) {
            res.emplace_back(node->val);
            return;
        }
        preorder(node->left, res);
        preorder(node->right, res);
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

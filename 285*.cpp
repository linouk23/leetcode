// 285. Inorder Successor in BST - https://leetcode.com/problems/inorder-successor-in-bst

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Idea: BS in BST: what to do when key == node->val?
// cause we want to find successor (bigger val)
// => go to right subtree
// Think about max value (corner case) -> need to return nullptr
// Think about min value (corner case) -> need to store parent node
// successor for 5 in 5 10 15 (update when turning L or R?)
// corner cases -> when turning left, initially succ = nullptr
// and then answer for 15 will be nullptr
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr || p == nullptr) { return nullptr; }
        int key = p->val;
        auto cur = root;
        TreeNode* succ = nullptr;
        while (cur) {
            if (cur->val > key) {
                succ = cur;
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return succ;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

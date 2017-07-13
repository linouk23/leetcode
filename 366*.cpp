// 366. Find Leaves of Binary Tree - https://leetcode.com/problems/find-leaves-of-binary-tree

#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//private:
//    vector<vector<int>> result;
//    bool isLeaf(TreeNode* node) {
//        if (node == nullptr) { return false; }
//        return !node->left && !node->right;
//    }
//    TreeNode* preorder(TreeNode* node, vector<int> &leaves) {
//        if (node == nullptr) { return nullptr; }
//        if (isLeaf(node)) {
//            leaves.emplace_back(node->val);
//            return nullptr;
//        }
//        node->left  = preorder(node->left, leaves);
//        node->right = preorder(node->right, leaves);
//        return node;
//    }
//public:
//    vector<vector<int>> findLeaves(TreeNode* root) {
//        while (!isLeaf(root)) {
//            vector<int> leaves;
//            preorder(root, leaves);
//            result.emplace_back(leaves);
//        }
//        return result;
//    }
//};


// Index == height
// The height of a node is the number of edges from the node to the deepest leaf.
// Bottom up approach.
class Solution {
private:
    vector<vector<int>> result;
    int postorder(TreeNode* node) {
        // Returns zero for leaves.
        if (node == nullptr) { return -1; }
        int leftHeight = postorder(node->left);
        int rightHeight = postorder(node->right);
        int height = 1 + max(leftHeight, rightHeight);
        if ((int)result.size() <= height) {
            result.push_back({});
        }
        result[height].emplace_back(node->val);
        return height;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        postorder(root);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

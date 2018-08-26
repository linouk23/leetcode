// 257. Binary Tree Paths - https://leetcode.com/problems/binary-tree-paths

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
private:
    bool isLeaf(TreeNode* node) {
        if (node == nullptr) { return false; }
        return !node->left && !node->right;
    }
    void preorder(TreeNode* root, string pathSoFar, vector<string> &paths) {
        if (root == nullptr) { return; }
        pathSoFar.append("->" + to_string(root->val));
        if (isLeaf(root)) {
            paths.emplace_back(pathSoFar.substr(2));
            return;
        }
        preorder(root->left, pathSoFar, paths);
        preorder(root->right, pathSoFar, paths); 
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root != nullptr) { preorder(root, "", paths); }
        return paths;
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

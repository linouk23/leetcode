// 543. Diameter of Binary Tree - https://leetcode.com/problems/diameter-of-binary-tree

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
    int result = 0;
public:
    int postorder(TreeNode* node) {
        if (node == nullptr) { return 0; }
        int left_result = postorder(node->left);
        int right_result = postorder(node->right);
        result = max(result, left_result + right_result);
        return max(left_result, right_result) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        postorder(root);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

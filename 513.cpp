// 513. Find Bottom Left Tree Value - https://leetcode.com/problems/find-bottom-left-tree-value

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
    pair<int, int> result = {INT_MIN, INT_MIN};
public:
    void postorder(TreeNode* node, int level) {
        if (node == nullptr) { return; }
        postorder(node->left, level + 1);
        postorder(node->right, level + 1);
        if (result.second < level) {
            result = {node->val, level};
        }
    }
    
    int findBottomLeftValue(TreeNode* root) {
        postorder(root, 0);
        return result.first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

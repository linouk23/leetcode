// 337. House Robber III - https://leetcode.com/problems/house-robber-iii

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
    unordered_map<TreeNode*, int> dp;
    void postorder(TreeNode* node) {
        if (node == nullptr) { return; }
        postorder(node->left);
        postorder(node->right);
        dp[node] = max(dp[node->left] + dp[node->right],
                       (node->left  ? dp[node->left->left]   : 0) +
                       (node->left  ? dp[node->left->right]  : 0) +
                       (node->right ? dp[node->right->left]  : 0) +
                       (node->right ? dp[node->right->right] : 0) +
                       node->val);
    }
public:
    int rob(TreeNode* root) {
        dp[nullptr] = 0;
        postorder(root);
        return dp[root];
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

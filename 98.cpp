// 98. Validate Binary Search Tree - https://leetcode.com/problems/validate-binary-search-tree

#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool is_valid_helper(TreeNode* node, long long min_val, long long max_val) {
        if (node == nullptr) { return true; }
        if ((long long)node->val > min_val && (long long)node->val < max_val) {
            return is_valid_helper(node->left, min_val, node->val) &&
                   is_valid_helper(node->right, node->val, max_val);
        }
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) { return true; }
        long long INF = 1e10;
        return is_valid_helper(root->left, -INF, root->val) &&
        is_valid_helper(root->right, root->val, INF);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

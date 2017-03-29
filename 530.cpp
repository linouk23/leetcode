// 530. Minimum Absolute Difference in BST - https://leetcode.com/problems/minimum-absolute-difference-in-bst

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
    int min_diff = INT_MAX;
    int prev_val;
    bool is_fst_node = true;
public:
    void in_order(TreeNode* root) {
        if (!root) { return; }
        in_order(root->left);
        if (!is_fst_node) {
            min_diff = min(min_diff, abs(root->val - prev_val));
        } else {
            is_fst_node = false;
        }
        prev_val = root->val;
        in_order(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        in_order(root);
        return min_diff;
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

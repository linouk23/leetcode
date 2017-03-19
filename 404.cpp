// 404. Sum of Left Leaves - https://leetcode.com/problems/sum-of-left-leaves

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
public:
    bool is_leaf(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }

        return root->left  == nullptr &&
               root->right == nullptr;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        if (is_leaf(root->left)) {
            return root->left->val + sumOfLeftLeaves(root->right);
        }

        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.sumOfLeftLeaves(nullptr) == 0);

    return 0;
}

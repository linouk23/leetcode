// 104. Maximum Depth of Binary Tree - https://leetcode.com/problems/maximum-depth-of-binary-tree

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.maxDepth(nullptr) == 0);

    return 0;
}

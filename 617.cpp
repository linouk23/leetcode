// 617. Merge Two Binary Trees - https://leetcode.com/problems/merge-two-binary-trees

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
    int get_val(TreeNode* n1, TreeNode* n2) {
        int val1 = (n1 == nullptr) ? 0 : n1->val;
        int val2 = (n2 == nullptr) ? 0 : n2->val;
        return val1 + val2;
    }
    TreeNode* preorder(TreeNode* n1, TreeNode* n2) {
        if (n1 == nullptr && n2 == nullptr) { return nullptr; }
        auto root = new TreeNode(get_val(n1, n2));
        root->left = preorder(n1 == nullptr ? n1 : n1->left,
                            n2 == nullptr ? n2 : n2->left);
        root->right = preorder(n1 == nullptr ? n1 : n1->right,
                             n2 == nullptr ? n2 : n2->right);
        return root;
    }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return preorder(t1, t2);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

// 606. Construct String from Binary Tree - https://leetcode.com/problems/construct-string-from-binary-tree

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
public:
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string result = to_string(t->val);
        
        if (t->left) {
            result += "(" + tree2str(t->left) + ")";
        }
        else if (t->right) {
            result += "()";
        }
        
        if (t->right) {
            result += "(" + tree2str(t->right) + ")";
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

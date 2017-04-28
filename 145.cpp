// 145. Binary Tree Postorder Traversal - https://leetcode.com/problems/binary-tree-postorder-traversal

#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Preorder traversal is root-left-right,
// and post order is left-right-root.
// Modify the code for pre-order to make it root-right-left,
// and then reverse the output so that we can get left-right-root.

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) { return result; }
        
        stack<TreeNode*> st;
        st.emplace(root);
        while(!st.empty()) {
            TreeNode* cur = st.top(); st.pop();
            result.emplace_back(cur->val);
            vector<TreeNode*> children = {cur->left, cur->right};
            for (const auto& child : children) {
                if (child == nullptr) { continue; }
                st.emplace(child);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

// 106. Construct Binary Tree from Inorder and Postorder Traversal - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    unordered_map<int, int> hashmap;
    vector<int> postorder_, inorder_;
public:
    TreeNode* helper(int post_start, int in_start, int in_finish) {
        if (in_finish < in_start) { return nullptr; }
        
        TreeNode* node = new TreeNode(postorder_[post_start]);
        
        int post_start_inorder = hashmap[postorder_[post_start]];
        
        int right_subtree_size = in_finish - post_start_inorder;
        node->left = helper(post_start - right_subtree_size - 1, in_start, post_start_inorder - 1);
        node->right = helper(post_start - 1, post_start_inorder + 1, in_finish);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = (int)postorder.size();
        if (n == 0) {
            return nullptr;
        }
        
        postorder_ = postorder;
        inorder_ = inorder;
        
        for (int index = 0; index < n; ++index) {
            int key = inorder[index];
            hashmap[key] = index;
        }
        int root_in_post = n - 1;
        return helper(root_in_post, 0, n - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

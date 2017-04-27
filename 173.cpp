// 173. Binary Search Tree Iterator - https://leetcode.com/problems/binary-search-tree-iterator

#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        pushLeftSubtree(root);
    }
    
    void pushLeftSubtree(TreeNode* node) {
        while(node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* cur = st.top(); st.pop();
        int result = cur->val;
        pushLeftSubtree(cur->right);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

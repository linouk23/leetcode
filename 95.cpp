// 95. Unique Binary Search Trees II - https://leetcode.com/problems/unique-binary-search-trees-ii

#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Idea:
// Inorder traversal for any BST with nodes 1 to n: 1, 2, ..., n.

class Solution {
public:
    vector<TreeNode*> generate(int start, int finish) {
        vector<TreeNode*> result;
        if (start > finish) {
            result.emplace_back(nullptr);
            return result;
        } else if (start == finish) {
            result.emplace_back(new TreeNode(start));
            return result;
        }
        for (int root_val = start; root_val <= finish; ++root_val) {
            auto left_subtrees = generate(start, root_val - 1);
            auto right_subtrees = generate(root_val + 1, finish);
            
            for (auto left_subtree : left_subtrees) {
                for (auto right_subtree : right_subtrees) {
                    TreeNode* root = new TreeNode(root_val);
                    root->left = left_subtree;
                    root->right = right_subtree;
                    result.emplace_back(root);
                }
            }
        }
        return result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) { return {}; }
        return generate(1, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

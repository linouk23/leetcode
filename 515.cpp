// 515. Find Largest Value in Each Tree Row - https://leetcode.com/problems/find-largest-value-in-each-tree-row

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
    vector<int> result;
public:
    void preorder(TreeNode* node, int level) {
        if (node == nullptr) { return; }
        if (result.size() <= level) {
            result.emplace_back(INT_MIN);
        }
        result[level] = max(result[level], node->val);
        preorder(node->left, level + 1);
        preorder(node->right, level + 1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        preorder(root, 0);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

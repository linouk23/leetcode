// 314. Binary Tree Vertical Order Traversal - https://leetcode.com/problems/binary-tree-vertical-order-traversal

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Use map to avoid the 2nd traversal (no need to determine min/max width).
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) { return result; }
        map<int, vector<int>> table;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int level = p.second;
            table[level].emplace_back(p.first->val);
            if (p.first->left) {
                q.push({p.first->left, level - 1});
            }
            if (p.first->right) {
                q.push({p.first->right, level + 1});
            }
        }
        // The keys are sorted (from left to right branch).
        for (const auto p : table) {
            result.emplace_back(p.second);
        }
        return result;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

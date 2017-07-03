// 103. Binary Tree Zigzag Level Order Traversal - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) { return {}; }
        vector<vector<int> > result;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int level;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            level = p.second;
            if (result.size() == level) { result.push_back({}); }
            result[level].emplace_back(p.first->val);
            auto vec = {p.first->left, p.first->right};
            for (auto node : vec) {
                if (node == nullptr) { continue; }
                q.push({node, p.second + 1});
            }
        }
        for (int idx = 0; idx < (int)result.size(); ++idx) {
            if (idx % 2 == 0) { continue; }
            reverse(result[idx].begin(), result[idx].end());
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

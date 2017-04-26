// 107. Binary Tree Level Order Traversal II - https://leetcode.com/problems/binary-tree-level-order-traversal-ii

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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        if (!root) { return result; }
        
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> dist;
        dist[root] = 0;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            if (result.size() <= dist[cur]) {
                result.emplace_back();
            }
            result[dist[cur]].push_back(cur->val);
            if (cur->left) {
                q.push(cur->left);
                dist[cur->left] = dist[cur] + 1;
            }
            if (cur->right) {
                q.push(cur->right);
                dist[cur->right] = dist[cur] + 1;
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

// 113. Path Sum II - https://leetcode.com/problems/path-sum-ii

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
    vector<vector<int> > result;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        pre_order(root, 0, sum, {});
        return result;
    }
    
    void pre_order(TreeNode* node, int cur_sum, int target_sum, vector<int> path) {
        if (node == nullptr) { return; }
        cur_sum += node->val;
        path.emplace_back(node->val);
        
        if (is_leaf(node) && cur_sum == target_sum) {
            result.emplace_back(path);
        }
        pre_order(node->left, cur_sum, target_sum, path);
        pre_order(node->right, cur_sum, target_sum, path);
        path.pop_back();
    }
    
    bool is_leaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

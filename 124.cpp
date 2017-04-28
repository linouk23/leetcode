// 124. Binary Tree Maximum Path Sum - https://leetcode.com/problems/binary-tree-maximum-path-sum

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
    int answer = INT_MIN;
public:
    int postorder(TreeNode* node) {
        if (node == nullptr) { return 0; }
        int L = postorder(node->left);
        int R = postorder(node->right);
        int max_side_sum = max(0, max(L, R)) + node->val;
        int sum_highest_node = max(0, max(L, max(R, L + R))) + node->val;
        answer = max(answer, sum_highest_node);
        return max_side_sum;
    }
    
    int maxPathSum(TreeNode* root) {
        postorder(root);
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

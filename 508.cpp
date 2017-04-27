// 508. Most Frequent Subtree Sum - https://leetcode.com/problems/most-frequent-subtree-sum

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
    unordered_map<int, int> hashtable;
public:
    int postorder(TreeNode* node) {
        if (node == nullptr) { return 0; }
        int left_tree_sum = postorder(node->left);
        int right_tree_sum = postorder(node->right);
        int total_sum = left_tree_sum + node->val + right_tree_sum;
        hashtable[total_sum] += 1;
        return total_sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        postorder(root);
        int max_value = INT_MIN;
        for (const auto & p : hashtable) {
            max_value = max(max_value, p.second);
        }
        vector<int> result;
        for (const auto & p : hashtable) {
            if (p.second == max_value) {
                result.emplace_back(p.first);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

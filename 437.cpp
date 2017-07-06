// 437. Path Sum III - https://leetcode.com/problems/path-sum-iii

#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//27ms
//class Solution {
//private:
//    // Returns number of ways containing this node
//    int sumUp(TreeNode* node, int sum_so_far, int target) {
//        // if use sum_so_far == target -> problem with multiple nullptr
//        if (node == nullptr) { return 0; }
//        int result = 0;
//        int cur_sum = sum_so_far + node->val;
//        if (cur_sum == target) {
//            ++result;
//        }
//        // e.g., 0 -> 5 -> -5 = 0 (there're 2 ways).
//        // building paths:
//        // 1) node---node->left---...
//        // 2) node---node->right---...
//        return result + sumUp(node->left, cur_sum, target)
//                      + sumUp(node->right, cur_sum, target);
//
//    }
//public:
//    int pathSum(TreeNode* root, int sum) {
//        if (root == nullptr) { return 0; }
//        // Rec to start a path from every possible node + start a path from root.
//        return pathSum(root->left, sum) + pathSum(root->right, sum) + sumUp(root, 0, sum);
//    }
//};

// 12 ms
class Solution {
private:
    int result = 0;
    // sum -> num of ways
    unordered_map<int, int> prefix = {
        // Base case.
        {0, 1},
    };
    void helper(TreeNode* node, int sum_so_far, int target) {
        if (node == nullptr) { return; }
        int cur_sum = sum_so_far + node->val;
        result += prefix[cur_sum - target];
        prefix[cur_sum] += 1;
        helper(node->left, cur_sum, target);
        helper(node->right, cur_sum, target);
        // Kinda push_back/pop_back
        prefix[cur_sum] -= 1;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        helper(root, 0, sum);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

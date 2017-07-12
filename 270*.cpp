// 270. Closest Binary Search Tree Value - https://leetcode.com/problems/closest-binary-search-tree-value

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    double result;
    void tryToUpdateResult(double candidate, double target) {
        if (fabs(result - target) >= fabs(candidate - target)) {
            result = candidate;
        }
    }
public:
    int closestValue(TreeNode* root, double target) {
        result = root->val;
        while (root) {
            if (root->val == target) { return target; }
            
            tryToUpdateResult(root->val, target);
            // root->val an upper (lower) bound -> find lower (upper) bound,
            // using main property of BST.
            root = (root->val < target) ? root->right : root->left;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 100. Same Tree - https://leetcode.com/problems/same-tree

#include <bits/stdc++.h>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr) {
            return q == nullptr;
        }
        if (q == nullptr) {
            return false;
        }

        return p->val == q->val && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.isSameTree(nullptr, nullptr) == true);

    return 0;
}

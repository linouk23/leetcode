// 501. Find Mode in Binary Search Tree - https://leetcode.com/problems/find-mode-in-binary-search-tree

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
private:
    TreeNode* prev = nullptr;
    vector<int> answer;
    int consq_count = 0;
    int max_count = 0;
public:
    void update(TreeNode* root) {
        if (!prev || root->val == prev->val) {
            ++consq_count;
            if (consq_count > max_count) {
                max_count = consq_count;
                answer.clear();
                answer.emplace_back(root->val);
            } else if (consq_count == max_count) {
            answer.emplace_back(root->val);
            }
        } else {
            consq_count = 1;
            if (consq_count == max_count) {
                answer.emplace_back(root->val);
            }
        }

        prev = root;
    }

    void in_order(TreeNode* root) {
        if (!root) return;

        in_order(root->left);
        update(root);
        in_order(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        in_order(root);
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

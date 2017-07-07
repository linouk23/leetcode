// 637. Average of Levels in Binary Tree - https://leetcode.com/problems/average-of-levels-in-binary-tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr) { return {}; }
        queue<pair<TreeNode*, int> > q;
        vector<vector<double>> levels;
        q.push({root, 0});
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            if (p.second == (int)levels.size()) {
                levels.push_back({});
            }
            levels[p.second].emplace_back((double)p.first->val);
            vector<TreeNode*> children = {p.first->left, p.first->right};
            for (const auto &son : children) {
                if (son == nullptr) { continue; }
                q.push({son, p.second + 1});
            }
        }
        vector<double> average;
        for (const auto &vec : levels) {
            int len = (int)vec.size();
            double sum = accumulate(vec.begin(), vec.end(), 0.0);
            average.emplace_back(sum / (double)len);
        }
        return average;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

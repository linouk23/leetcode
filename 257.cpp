// 257. Binary Tree Paths - https://leetcode.com/problems/binary-tree-paths

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
    vector<string> answer;
public:
    void dfs(TreeNode* node, string path) {
        if (!node) { return; }
        if (!node->left && !node->right) {
            path += to_string(node->val);
            answer.emplace_back(path);
            return;
        }
        path += to_string(node->val);
        path += "->";
        dfs(node->left, path);
        dfs(node->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) { return answer; }
        dfs(root, "");

        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

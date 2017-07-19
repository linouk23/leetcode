// 333. Largest BST Subtree - https://leetcode.com/problems/largest-bst-subtree

#include "bits/stdc++.h"
#include "gtest/gtest.h"
#include <GoogleMock/GoogleMock.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    struct Result {
        int size;
        int res_so_far;
    };
    Result postorder(TreeNode* node) {
        if (node == nullptr) { return {0, 0}; }
        auto left_res  = postorder(node->left);
        auto right_res = postorder(node->right);
        int tree_size = left_res.size + right_res.size + 1;
        int result = max({left_res.res_so_far,
                          right_res.res_so_far,
                          tree_size});
        return { tree_size, result };
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        return max(postorder(root->left).res_so_far,
                   postorder(root->right).res_so_far);
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

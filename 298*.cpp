// 298. Binary Tree Longest Consecutive Sequence - https://leetcode.com/problems/binary-tree-longest-consecutive-sequence

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    struct ExpNode {
        int result, result_so_far;
    };
    ExpNode postorder(TreeNode* node) {
        if (node == nullptr) { return {0, 0}; }
        auto left  = postorder(node->left);
        auto right = postorder(node->right);
        ExpNode result;
        if ((node->left) && node->val + 1 == node->left->val) {
            result.result = left.result + 1;
        } else {
            result.result = 1;
        }
        if ((node->right) && node->val + 1 == node->right->val) {
            result.result = max(result.result, right.result + 1);
        }
        result.result_so_far = max({result.result, left.result_so_far,
                                    right.result_so_far});
        return result;
    }
public:
    int longestConsecutive(TreeNode* root) {
        return postorder(root).result_so_far;
    }
};

const string null = "#";
const char delim = ',';

class Tree {
private:
    static TreeNode* helper(vector<string> tokens, int &idx) {
        string val = tokens[idx];
        if (val == null) {
            ++idx;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(val));
        ++idx;
        node->left = helper(tokens, idx);
        node->right = helper(tokens, idx);
        return node;
    }
public:
    static TreeNode* deserialize(string str) {
        vector<string> tokens;
        stringstream ss(str);
        string token;
        while(getline(ss, token, delim)) {
            tokens.emplace_back(token);
        }
        int start = 0;
        return helper(tokens, start);
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    string tree = "1,#,3,2,#,#,4,#,5,#,#";
    // 345 - inc
    EXPECT_EQ(3, sol.longestConsecutive(Tree::deserialize(tree)));
    tree = "2,#,3,2,1,#,#,#,#";
    // 23 - inc
    EXPECT_EQ(2, sol.longestConsecutive(Tree::deserialize(tree)));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

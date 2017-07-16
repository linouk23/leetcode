// 549. Binary Tree Longest Consecutive Sequence II - https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

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
    struct Result {
        int inc, dec, res_so_far;
    };
    Result postorder(TreeNode* node) {
        if (node == nullptr) { return {0, 0, 0}; }
        
        // Works for node, node->left = nullptr, node->right = nullptr
        Result r = {1, 1, 1};
        auto children = {node->left, node->right};
        // Trick: call postorder in loop (don't duplicate the code)
        for (const auto &ch : children) {
            if (!ch) { continue; }
            auto rc = postorder(ch);
            // from the bottom -> inc, from the top -> dec
            if (ch->val + 1 == node->val) {
                r.inc = max(r.inc, rc.inc + 1);
            }
            if (ch->val - 1 == node->val) {
                r.dec = max(r.dec, rc.dec + 1);
            }
        }
        // Try to update the best res with current path (id. by root).
        // Counted the root twice, that's why we need minus one.
        r.res_so_far = max(r.res_so_far, r.inc + r.dec - 1);
        return r;
    }
public:
    int longestConsecutive(TreeNode* root) {
        return postorder(root).res_so_far;
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
    string tree = "1,2,#,#,3,#,#";
    EXPECT_EQ(2, sol.longestConsecutive(Tree::deserialize(tree)));
    tree = "2,1,#,#,3,#,#";
    EXPECT_EQ(3, sol.longestConsecutive(Tree::deserialize(tree)));
}


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

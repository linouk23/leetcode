// 250. Count Univalue Subtrees - https://leetcode.com/problems/count-univalue-subtrees

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
    int result = 0;
    struct ExpNode {
        int val, count_so_far;
    };
    ExpNode helper(TreeNode* node) {
        if (node == nullptr) { return {INT_MIN, 0}; }
        ExpNode left = helper(node->left);
        ExpNode right = helper(node->right);
        
        if (left.val == INT_MIN || right.val == INT_MIN) {
            left.val = right.val = max(left.val, right.val);
            if (left.val == INT_MIN) {
                left.val = right.val = node->val;
            }
        }
        
        int count = left.count_so_far + right.count_so_far;
        if (left.val  != right.val) { return {node->val, count}; }
        if (node->val != left.val)  { return {node->val, count}; }
        count += 1;
        return {node->val, count};
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        return helper(root).count_so_far;
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
    string tree = "5,#,#";
    EXPECT_EQ(1, sol.countUnivalSubtrees(Tree::deserialize(tree)));
    tree = "5,1,5,#,#,5,#,#,5,#,5,#,#";
    EXPECT_EQ(4, sol.countUnivalSubtrees(Tree::deserialize(tree)));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

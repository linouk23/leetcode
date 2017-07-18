// 450. Delete Node in a BST - https://leetcode.com/problems/delete-node-in-a-bst

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

// Phil Jackson rec: node -> triangle: |> -> return node
// node->left = f(node->left, ...) -> instead of passing (parent, cur)
class Solution {
private:
    // max value node
    TreeNode* find_rightmost_leaf(TreeNode* node) {
        auto cur = node;
        while (cur->right) {
            cur = cur->right;
        }
        return cur;
    }
    TreeNode* deleteNodeHelper(TreeNode* node, int key) {
        if (node == nullptr) { return nullptr; }
        
        if (node->val == key) {
            // Case #1: Node hasn't got a left subtree
            // 6 -> 8 -> 10 ====> 6 -> 10
            // 6 -> 8       ====> 6 -> nullptr
            if (!node->left) { return node->right; }
            
            // Case #2: Node has got a left subtree
            // find for the rightmost leaf (max value)
            // in left subtree, set it's value to current
            // node and then delete that leaf.
            node->val = find_rightmost_leaf(node->left)->val;
            // 8 6 10, 8 -> 6 10
            node->left = deleteNode(node->left, node->val);
            return node;
        }
        
        if (node->val > key) {
            node->left = deleteNodeHelper(node->left, key);
        } else {
            node->right = deleteNodeHelper(node->right, key);
        }
        return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteNodeHelper(root, key);
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
    // Encodes a tree to a single string.
    static string serialize(TreeNode* root) {
        string result;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            auto node = st.top(); st.pop();
            if (node == nullptr) {
                result += null;
                result.push_back(delim);
                continue;
            }
            result += to_string(node->val);
            result.push_back(delim);
            
            st.push(node->right);
            st.push(node->left);
        }
        return result;
    }
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
    string tree = "6,#,#,";
    EXPECT_EQ("6,#,#,", Tree::serialize(sol.deleteNode(Tree::deserialize(tree), 8)));
    
    tree = "6,#,8,#,10,#,#,";
    EXPECT_EQ("6,#,10,#,#,", Tree::serialize(sol.deleteNode(Tree::deserialize(tree), 8)));

    tree = "8,6,#,7,#,#,10,#,#,";
    EXPECT_EQ("7,6,#,#,10,#,#,", Tree::serialize(sol.deleteNode(Tree::deserialize(tree), 8)));
    
    tree = "8,6,#,#,10,#,#,";
    EXPECT_EQ("6,#,10,#,#,", Tree::serialize(sol.deleteNode(Tree::deserialize(tree), 8)));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

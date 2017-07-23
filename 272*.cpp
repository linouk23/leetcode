// 272. Closest Binary Search Tree Value II - https://leetcode.com/problems/closest-binary-search-tree-value-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

class Solution {
private:
    bool closer(int n1, int n2, double target) {
        return (abs(1.0 * n1 - target) <= abs(1.0 * n2 - target));
    }
    void inorder(deque<int> &deq, TreeNode* root, double target, int k) {
        if (root == nullptr) { return; }
        inorder(deq, root->left, target, k);
        if ((int)deq.size() == k) {
            // Increasing seq in deque.
            if (closer(root->val, deq.front(), target)) {
                deq.pop_front();
                deq.emplace_back(root->val);
            } else {
                return;
            }
        } else {
            deq.emplace_back(root->val);
        }
        inorder(deq, root->right, target, k);
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> deq;
        inorder(deq, root, target, k);
        // Trick.
        return vector<int>(deq.begin(), deq.end());
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    vector<int> expected = {1,2,3,4};
    string tree = "10,2,1,#,#,3,#,4,#,#,16,#,#,";
    EXPECT_EQ(expected, sol.closestKValues(Tree::deserialize(tree), 4.5, 4));
    expected = {10};
    EXPECT_EQ(expected, sol.closestKValues(Tree::deserialize(tree), 10.0, 1));
    expected = {10,16};
    EXPECT_EQ(expected, sol.closestKValues(Tree::deserialize(tree), 13.0, 2));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

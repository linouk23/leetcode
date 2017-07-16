// 255. Verify Preorder Sequence in Binary Search Tree - https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Idea: recover inorder sequence from preorder sequence of a BST.
// q using 2 stacks, stack invariant (dec seq).
// inorder invariant: inc seq
class Solution {
public:
    bool verifyPreorder(vector<int> preorder){
        stack<int> st, inorder;
        // Recover inorder sequence from preorder sequence of a BST.
        // inorder = sorted(preorder)
        for (int v : preorder) {
            if (!inorder.empty() && v < inorder.top()) {
                // inorder should be inc seq
                return false;
            }
            // Like implementing q using 2 stacks
            while (!st.empty() && v > st.top()) {
                int top_vertex = st.top();
                st.pop();
                inorder.push(top_vertex);
            }
            st.push(v);
        }
        return true;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_FALSE(sol.verifyPreorder({10, 14, 1}));
    EXPECT_FALSE(sol.verifyPreorder({15, 9, 8, 13, 20, 14, 24}));
    
    EXPECT_TRUE(sol.verifyPreorder({10, 14, 15}));
    EXPECT_TRUE(sol.verifyPreorder({10, 9, 8}));
    EXPECT_TRUE(sol.verifyPreorder({15, 9, 8, 13, 20, 18, 24}));
}

TEST(SolutionTest, Empty) {
    Solution sol;
    EXPECT_TRUE(sol.verifyPreorder({}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

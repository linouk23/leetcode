// 536. Construct Binary Tree from String - https://leetcode.com/problems/construct-binary-tree-from-string

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
public:
    TreeNode* str2tree(string s) {
        int idx = 0;
        return s.size() == 0 ? nullptr : build(s, idx);
    }
    
private:
    TreeNode* build(const string& s, int& idx) {
        int start = idx;
        if (s[idx] == '-') {
            ++idx;
        }
        while (isdigit(s[idx])) {
            ++idx;
        }
        
        int num = stoi(s.substr(start, idx - start));
        TreeNode* node = new TreeNode(num);
        if (s[idx] == '(') {
            node->left = build(s, ++idx);
            ++idx;    // )
        }
        if (s[idx] == '(') {
            node->right = build(s, ++idx);
            ++idx;    // )
        }
        return node;
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
    string tree = "4(2(3)(1))(6(5))";
    string expected = "4,2,3,#,#,1,#,#,6,5,#,#,#,";
    EXPECT_EQ(expected, Tree::serialize(sol.str2tree(tree)));
}


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

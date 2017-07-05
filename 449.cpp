// 449. Serialize and Deserialize BST - https://leetcode.com/problems/serialize-and-deserialize-bst

#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    string null_str = "#";
    char delim = ',';
    TreeNode* deserialize(int &start, const vector<string> &data) {
        if (data[start] == null_str) {
            ++start;
            return nullptr;
        }
        int value = stoi(data[start]);
        TreeNode* node = new TreeNode(value);
        ++start;
        node->left = deserialize(start, data);
        node->right = deserialize(start, data);
        return node;
    }
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            auto node = st.top(); st.pop();
            if (node == nullptr) {
                result += null_str;
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
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        vector<string> tokens;
        while(getline(ss, token, delim)) {
            tokens.emplace_back(token);
        }
        int start = 0;
        return deserialize(start, tokens);
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 297. Serialize and Deserialize Binary Tree - https://leetcode.com/problems/serialize-and-deserialize-binary-tree

#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
private:
    string str;
    char separator = ',';
    int index = 0;
    vector<string> keys;
public:
    void preorder(TreeNode* node) {
        if (node == nullptr) {
            str += "#,";
            return;
        }
        str += to_string(node->val);
        str += separator;
        preorder(node->left);
        preorder(node->right);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        preorder(root);
        return str;
    }
    
    TreeNode* rec() {
        string key = keys[index++];
        if (key == "#") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(key));
        root->left = rec();
        root->right = rec();
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        string token;
        
        while(getline(ss, token, separator)) {
            keys.emplace_back(token);
        }
        TreeNode* root = rec();
        return root;
    }
};


int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

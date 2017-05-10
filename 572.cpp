// 572. Subtree of Another Tree - https://leetcode.com/problems/subtree-of-another-tree

#include "bits/stdc++.h"

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
    string null_val = "#";
    string unique_ch = "?";
    void serialize(TreeNode* node, vector<string> &tokens) {
        if (node == nullptr) {
            tokens.push_back(null_val);
            return;
        }
        tokens.push_back(to_string(node->val));
        serialize(node->left, tokens);
        serialize(node->right, tokens);
    }
    
    vector<int> z(vector<string> strs) {
        int n = (int)strs.size();
        vector<int> z(n);
        int L = 0, R = 0;
        for (int index = 1; index < n; ++index) {
            z[index] = max(0, min(z[index - L], R - index + 1));
            while (index + z[index] < n && strs[z[index]] == strs[index + z[index]]) {
                L = index;
                R = index + z[index];
                ++z[index];
            }
        }
        return z;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        vector<string> pattern, text;
        serialize(s, text);
        serialize(t, pattern);
        vector<string> text_for_z;
        text_for_z.insert(text_for_z.end(), pattern.begin(), pattern.end());
        text_for_z.push_back(unique_ch);
        text_for_z.insert(text_for_z.end(), text.begin(), text.end());
        vector<int> result = z(text_for_z);
        for (int num : result) {
            if (num == (int)pattern.size()) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 331. Verify Preorder Serialization of a Binary Tree - https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree

#include "bits/stdc++.h"

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// During building, we record the difference between out degree and in degree:
// diff = outdegree - indegree. When the next node comes, we then decrease diff by 1,
// because the node provides an in degree.
// If the node is not null, we increase diff by 2, because it provides two out degrees.
// If a serialization is correct, diff should never be negative and diff will be zero when
// finished.

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) { return true; }
        istringstream ss(preorder);
        string token;
        vector<string> tokens;
        while(getline(ss, token, ',')) {
            tokens.emplace_back(token);
        }
        
        int diff = 1;
        for (auto token : tokens) {
            if (--diff < 0) return false;
            if (!(token == "#")) diff += 2;
        }
        return diff == 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

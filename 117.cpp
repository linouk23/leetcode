// 117. Populating Next Right Pointers in Each Node II - https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

#include "bits/stdc++.h"

using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    void connect(TreeLinkNode* root) {
        TreeLinkNode* head = nullptr; // head of the next level
        TreeLinkNode* leading = nullptr; // leading node of the next level
        auto cur = root; // cur node of the current level
        
        while (cur) {
            while (cur) {
                if (cur->left) {
                    if (leading == nullptr) {
                        head = cur->left;
                    } else {
                        leading->next = cur->left;
                    }
                    leading = cur->left;
                }
                if (cur->right) {
                    if (leading == nullptr) {
                        head = cur->right;
                    } else {
                        leading->next = cur->right;
                    }
                    leading = cur->right;
                }
                cur = cur->next;
            }
            cur = head;
            head = leading = nullptr;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

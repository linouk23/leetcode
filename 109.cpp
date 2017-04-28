// 109. Convert Sorted List to Binary Search Tree - https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

#include "bits/stdc++.h"

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    ListNode* next(ListNode* node) {
        return node->next;
    }
    
    // [start, finish)
    TreeNode* helper(ListNode* head, ListNode* tail) {
        if (head == tail) { return nullptr; }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail) {
            slow = next(slow);
            fast = next(next(fast));
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = helper(head, slow);
        root->right = helper(slow->next, tail);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, nullptr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

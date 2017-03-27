// 237. Delete Node in a Linked List - https://leetcode.com/problems/delete-node-in-a-linked-list

#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

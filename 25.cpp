// 25. Reverse Nodes in k-Group - https://leetcode.com/problems/reverse-nodes-in-k-group

#include "bits/stdc++.h"

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// For example,
// Given this linked list: 1->2->3->4->5
// For k = 2, you should return: 2->1->4->3->5
// For k = 3, you should return: 3->2->1->4->5
// k = 2, swap in pairs, temp, n->next->next = n, n->next = rec(temp)?
class Solution {
private:
    void reverse_list(ListNode* head, ListNode* tail) {
        ListNode* prev = nullptr;
        auto cur = head;
        bool canContinue = true;
        while (canContinue) {
            if (cur == tail) {
                canContinue = false;
            }
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    }
public:
    // Returns head of that group => recursion
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) { return head; }
        auto cur = head;
        for (int idx = 1; idx < k; ++idx) {
            cur = cur->next;
            if (!cur) { return head; }
        }
        // Cur is the last node in k-group.
        auto temp = cur->next;
        reverse_list(head, cur);
        head->next = reverseKGroup(temp, k);
        return cur;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

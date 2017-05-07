// 203. Remove Linked List Elements - https://leetcode.com/problems/remove-linked-list-elements

#include "bits/stdc++.h"

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto dummy = new ListNode(0);
        auto result = dummy;
        auto cur = head;
        while (cur != nullptr) {
            if (cur->val != val) {
                dummy = dummy->next = cur;
            }
            cur = cur->next;
        }
        dummy->next = nullptr;
        return result->next;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

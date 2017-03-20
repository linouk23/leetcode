// 2. Add Two Numbers - https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* pre_head = new ListNode(0);
        ListNode* head = pre_head;

        while(l1 || l2 || carry) {
            int num = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            int val = num % 10;
            carry = num / 10;

            head->next = new ListNode(val);
            head = head->next;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        return pre_head->next;
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

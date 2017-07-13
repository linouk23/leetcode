// 369. Plus One Linked List - https://leetcode.com/problems/plus-one-linked-list

#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto lastNotNine = dummy;
        auto cur = head;
        while (cur->next) {
            if (cur->val != 9) {
                lastNotNine = cur;
            }
            cur = cur->next;
        }
        // cur == last node
        if (cur->val != 9) {
            cur->val += 1;
            return dummy->next;
        }
        lastNotNine->val += 1;
        cur = lastNotNine;
        while (cur) {
            cur->val = 0;
        }
        return (dummy == lastNotNine) ? dummy : dummy->next;
    }
};

//example 1->8->9->7->9->9.
//Pointer i points to the first node before the tailing 9s, which is 7 in this case and pointer j points to the last node of the whole list, which is 9.
//
//If the value of j equals to 9, the sublist behind i should be updated. Increments the value of 1 by 1 and set the following nodes to be 0.
//If the value of j is not 9, just increments j.val by one.
//The use of dummy node:
//
//In the cases like 9->9->9, the answer should return dummy. (1->0->0->0)
//In other cases like 8->9->9, the answer should return dummy.next. (0->9->0->0, dummy is the first 0).

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 82. Remove Duplicates from Sorted List II - https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

#include "bits/stdc++.h"

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dum = new ListNode(0);
        auto cur = dum;
        auto L = head, R = head;
//        2->2->2->3
//        ^     ^
//        |     |
//        L     R
        while (R != nullptr) {
            while (R->next != nullptr && R->next->val == L->val) {
                R = R->next;
            }
            if (L == R) {
                // Trick.
                cur = cur->next = L;
            }
            R = R->next;
            L = R;
        }
        cur->next = nullptr;
        return dum->next;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

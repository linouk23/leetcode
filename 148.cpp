// 148. Sort List - https://leetcode.com/problems/sort-list

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    // Returns head of a merged list.
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr) { return head2; }
        if (head2 == nullptr) { return head1; }
        if (head1->val <= head2->val) {
            head1->next = merge(head1->next, head2);
            return head1;
        } else {
            head2->next = merge(head1, head2->next);
            return head2;
        }
    }
public:
    ListNode* sortList(ListNode* head) {
        // Already sorted.
        if (head == nullptr ||
            head->next == nullptr) { return head; }
        
        // Find halves.
        auto slow = head;
        auto fast = head;
        auto prev = slow;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        // fast->next = nullptr;
        auto fstHalve = sortList(head);
        auto sndHalve = sortList(slow);
        return merge(fstHalve, sndHalve);
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

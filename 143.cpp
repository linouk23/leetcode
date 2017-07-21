// 143. Reorder List - https://leetcode.com/problems/reorder-list

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
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        
        // Find the middle node using slow && fast pointers
        ListNode *p1 = head, *p2 = head->next;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        // Cut and reverse the half after middle
        // 1->2->3->4->5->6 to 1->2->3->6->5->4
        ListNode *head2 = p1->next;
        p1->next = NULL;
        
        p2 = head2->next;
        head2->next = NULL;
        while (p2) {
            p1 = p2->next;
            p2->next = head2;
            head2 = p2;
            p2 = p1;
        }
        
        // Start reorder one by one  1->2->3->6->5->4 to 1->6->2->5->3->4
        // Invariant: set p1->next = p2
        // (p1, p2) and then (p2, p1) etc
        for (p1 = head, p2 = head2; p1; ) {
            auto t = p1->next;
            p1 = p1->next = p2;
            p2 = t;
        }
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

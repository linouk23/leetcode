// 147. Insertion Sort List - https://leetcode.com/problems/insertion-sort-list

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
    void insert(ListNode* sortedHead, ListNode* node) {
        ListNode* prev = sortedHead;
        ListNode* cur = sortedHead->next;
        
        // prev -> cur
        // 5    ->  8
        // insert 7: prev -> 7 -> 8
        while (cur) {
            if (node->val <= cur->val &&
                node->val >= prev->val) {
                break;
            }
            
            prev = cur;
            cur = cur->next;
        }
        prev->next = node;
        node->next = cur;
    }
    void helper(ListNode* sortedHead, ListNode* unsortedHead) {
        if (unsortedHead == nullptr) { return; }
        ListNode* next = unsortedHead->next;
        insert(sortedHead, unsortedHead);
        helper(sortedHead, next);
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        helper(dummy, head);
        return dummy->next;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

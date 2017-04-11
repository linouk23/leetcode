// 86. Partition List - https://leetcode.com/problems/partition-list

#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) { return nullptr; }
        ListNode* list1 = new ListNode(0);
        ListNode* list2 = new ListNode(0);
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        
        while (head != nullptr) {
            if (head->val < x) {
                p1 = p1->next = head;
            } else {
                p2 = p2->next = head;
            }
            head = head->next;
        }
        p2->next = nullptr;
        p1->next = list2->next;
        return list1->next;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

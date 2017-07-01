// 61. Rotate List - https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0) { return head; }
        if (head == nullptr) { return head; }
        
        auto cur = head;
        
        int n = 0;
        while (cur->next != nullptr) {
            ++n;
            cur = cur->next;
        }
        ++n;
        k = k % n;
        int diff = (n - k);
        if (diff == 0) { return head; }
        
        cur->next = head;
        cur = head;
        --diff;
        while (diff--) {
            cur = cur->next;
        }
        auto result = cur->next;
        cur->next = nullptr;
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

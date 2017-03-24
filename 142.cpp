// 142. Linked List Cycle II - https://leetcode.com/problems/linked-list-cycle-ii

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
    ListNode* next(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        return head->next;
    }

    ListNode* detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            slow = next(slow);
            fast = next(next(fast));
        } while (slow != fast && fast != nullptr);

        if (fast == nullptr) {
            return nullptr;
        }

        slow = head;
        while (slow != fast) {
            slow = next(slow);
            fast = next(fast);
        }

        return slow;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.detectCycle(nullptr) == false);

    return 0;
}

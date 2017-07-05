// 24. Swap Nodes in Pairs - https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto dum = head->next;
        // 1 -> 2 -> 3(tmp) -> ...
        auto tmp = head->next->next;
        //   --
        // |    |
        // v    |
        // 1 -> 2   3(tmp) -> ...
        head->next->next = head;
        // Returns head of new list.
        // Trick.
        head->next = swapPairs(tmp);
        return dum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

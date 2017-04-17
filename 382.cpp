// 382. Linked List Random Node - https://leetcode.com/problems/linked-list-random-node

#include "bits/stdc++.h"

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* head;
    default_random_engine generator;
public:
    /** @param head The linked list's head.
     Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        uniform_real_distribution<double> distribution(0.0, 1.0);
        double break_point, rand_num;
        
        int length_so_far = 1;
        int result = 0;
        ListNode* node = head;
        while(node != nullptr) {
            break_point = 1.0 / ((double)length_so_far);
            rand_num = distribution(generator);
            if (rand_num <= break_point) {
                result = node->val;
            }
            node = node->next;
            ++length_so_far;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

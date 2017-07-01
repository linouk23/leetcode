// 138. Copy List with Random Pointer - https://leetcode.com/problems/copy-list-with-random-pointer

#include "bits/stdc++.h"

using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
private:
    unordered_map<RandomListNode*, RandomListNode*> hashmap;
    
    void checkAndMaybeCreateDuplicate(RandomListNode* node) {
        if (node == nullptr) { return; }
        if (hashmap.count(node)) { return; }
        hashmap[node] = new RandomListNode(node->label);
    }
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        auto cur = head;
        while (cur != nullptr) {
            auto vec = {cur, cur->next, cur->random};
            for (auto node : vec) {
                checkAndMaybeCreateDuplicate(node);
            }
            hashmap[cur]->next = hashmap[cur->next];
            hashmap[cur]->random = hashmap[cur->random];
            cur = cur->next;
        }
        return hashmap[head];
    }
};


int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

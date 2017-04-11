// 108. Convert Sorted Array to Binary Search Tree - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* createBST(vector<int>& nums, int start, int finish) {
        if (start > finish) { return nullptr; }
        int mid = start + (finish - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = createBST(nums, start, mid - 1);
        node->right = createBST(nums, mid + 1, finish);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums, 0, (int)nums.size() - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

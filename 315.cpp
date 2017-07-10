// 315. Count of Smaller Numbers After Self - https://leetcode.com/problems/count-of-smaller-numbers-after-self

#include "bits/stdc++.h"

using namespace std;

// O(N^2), 45ms
//class Solution {
//private:
//    int bin_search_ins(vector<int>& nums, int target) {
//        int n = (int)nums.size();
//        int L = -1, R = n;
//        while (R - L > 1) {
//            int M = L + (R - L) / 2;
//            if (target <= nums[M]) {
//                R = M;
//            } else {
//                L = M;
//            }
//        }
//        return R;
//    }
//public:
//    vector<int> countSmaller(vector<int> nums) {
//        if (nums.empty()) { return {}; }
//        int n = (int)nums.size();
//        vector<int> result(n, 0);
//        vector<int> sort_r_nums = {nums[n - 1]};
//        for (int idx = n - 2; idx >= 0; --idx) {
//            int num = nums[idx];
//            //                       0 1 2 3 4
//            // index to insert : 5, [1,2,5,5,6] -> 2
//            
//            int pos = bin_search_ins(sort_r_nums, num);
//            result[idx] = pos;
//            sort_r_nums.insert(sort_r_nums.begin() + pos, num);
//        }
//        return result;
//    }
//};

// O(N^2) -> O(N logN) in case of self balancing BS tree, 29ms
//struct MyTreeNode {
//    int val, count = 1, left_subtree_size;
//    MyTreeNode *left, *right;
//};
//
//class BST {
//private:
//    MyTreeNode* helper_insert(MyTreeNode* node, int val) {
//        if (node == nullptr) {
//            node = new MyTreeNode {val};
//        } else if (val == node->val) {
//            node->count += 1;
//        } else if (node->val > val) {
//            node->left_subtree_size += 1;
//            node->left = helper_insert(node->left, val);
//        } else {
//            node->right = helper_insert(node->right, val);
//        }
//        return node;
//    }
//    int helper_count(MyTreeNode* node, int val) {
//        if (node == nullptr) { return 0; }
//        
//        if (node->val == val) {
//            return node->left_subtree_size;
//        } else if (node->val > val) {
//            return helper_count(node->left, val);
//        } else { // (node->val < val)
//            return node->count +
//                   node->left_subtree_size +
//                   helper_count(node->right, val);
//        }
//    }
//public:
//    BST() { root = nullptr; }
//    void insert(int val) {
//        root = helper_insert(root, val);
//    }
//    int get_smaller_nodes(int val) {
//        return helper_count(root, val);
//    }
//private:
//    MyTreeNode* root;
//};
//
//class Solution {
//private:
//    BST tree;
//public:
//    vector<int> countSmaller(vector<int> nums) {
//        int n = (int)nums.size();
//        vector<int> result(n);
//        for (int idx = n - 1; idx >= 0; --idx) {
//            int num = nums[idx];
//            tree.insert(num);
//            result[idx] = tree.get_smaller_nodes(num);
//        }
//        return result;
//    }
//};

// For leetcode.
struct MyTreeNode {
    int val, count = 1, left_subtree_size = 0;
    MyTreeNode *left = nullptr, *right = nullptr;
    MyTreeNode(int v) : val(v) {}
};

class BST {
private:
    MyTreeNode* helper_insert(MyTreeNode* node, int val) {
        if (node == nullptr) {
            node = new MyTreeNode(val);
        } else if (val == node->val) {
            node->count += 1;
        } else if (node->val > val) {
            node->left_subtree_size += 1;
            node->left = helper_insert(node->left, val);
        } else {
            node->right = helper_insert(node->right, val);
        }
        return node;
    }
    int helper_count(MyTreeNode* node, int val) {
        if (node == nullptr) { return 0; }
        
        if (val == node->val) {
            return node->left_subtree_size;
        } else if (node->val > val) {
            return helper_count(node->left, val);
        } else { // (node->val < val)
            return node->count +
            node->left_subtree_size +
            helper_count(node->right, val);
        }
    }
public:
    BST() { root = nullptr; }
    void insert(int val) {
        root = helper_insert(root, val);
    }
    int get_smaller_nodes(int val) {
        return helper_count(root, val);
    }
private:
    MyTreeNode* root;
};

class Solution {
private:
    BST tree;
public:
    vector<int> countSmaller(vector<int> nums) {
        int n = (int)nums.size();
        vector<int> result(n);
        for (int idx = n - 1; idx >= 0; --idx) {
            int num = nums[idx];
            tree.insert(num);
            result[idx] = tree.get_smaller_nodes(num);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

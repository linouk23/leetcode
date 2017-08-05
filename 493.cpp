// 493. Reverse Pairs - https://leetcode.com/problems/reverse-pairs

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Seq:
// T[L, R] = T[L, R - 1] + subproblem
// T[0, R] = T[0, R - 1] + subproblem
// subproblem:
// num of pairs such that
// 1) i < R (OK)
// 2) nums[i] > 2*nums[R] (?)
// where i \in [0, R - 1]
// Result:
// T[0, n - 1]

typedef long long ll;

class SegmentTree {
private:
    vector<int> v_;
    int n;
    int nextPowerOf2(int n) const {
        int L = -1, R = 32;
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if ((1 << M) >= n) {
                R = M;
            } else {
                L = M;
            }
        }
        return (1 << R);
    }
    void buildTree() {
        for (int index = 0; index < n; ++index) {
            v_[index + n] = v_[index];
        }
        for (int index = n - 1; index >= 1; --index) {
            v_[index] = v_[2 * index] + v_[2 * index + 1];
        }
    }
public:
    SegmentTree(const vector<int> &v) {
        v_ = v;
        n = nextPowerOf2((int)v.size());
        // v_.resize(2 * n, 0);
        // buildTree();
        v_.assign(2 * n, 0);
    }
    void update(int idx, int val) {
        idx += n;
        v_[idx] = val;
        for (idx /= 2; idx >= 1; idx /= 2) {
            v_[idx] = v_[2 * idx] + v_[2 * idx + 1];
        }
    }
    
    int sum(int L, int R) const {
        L += n;
        R += n;
        int sum = 0;
        while (L <= R) {
            if (L % 2 == 1) { sum += v_[L++]; }
            if (R % 2 == 0) { sum += v_[R--]; }
            L /= 2;
            R /= 2;
        }
        return sum;
    }
};

class Solution {
private:
    int find(const SegmentTree& tree, int num, int start, int n) {
        // 2) nums[i] > 2*nums[R] (?)
        // where i \in [0, R - 1]
        // How many numbers >= upper are there in Segment Tree?
        // sum(start, n - 1), idx of sorted nums
        return tree.sum(start, n - 1);
    }
    int bin_search(const vector<pair<int, int> > &v, int num, int n) {
        ll num_to_find = 2LL * num + 1;
        int R = n;
        int L = -1;
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (v[M].first >= num_to_find) {
                R = M;
            } else {
                L = M;
            }
        }
        return R;
    }
public:
    int reversePairs(vector<int> nums) {
        if (nums.empty()) { return 0; }
        int n = (int)nums.size(), result = 0;
        vector<pair<int, int> > nums_idxs;
        for (int idx = 0; idx < n; ++idx) {
            nums_idxs.emplace_back(nums[idx], idx);
        }
        sort(nums_idxs.begin(), nums_idxs.end());
        unordered_map<int, int> idx_to_sorted_idx, num_to_idx;
        for (int idx = 0; idx < n; ++idx) {
            int num, unsorted_idx;
            tie(num, unsorted_idx) = nums_idxs[idx];
            idx_to_sorted_idx[unsorted_idx] = idx;
            if (!num_to_idx.count(num)) {
                num_to_idx[num] = idx;
            }
        }
        SegmentTree tree(nums);
        for (int idx = 0; idx < n; ++idx) {
            int num = nums[idx];
            int start = bin_search(nums_idxs, num, n);
            result += find(tree, num, start, n);
            tree.update(idx_to_sorted_idx[idx], 1);
        }
        return result;
    }
};
// 415ms

// Part:
// T[L, R] = T[L, M - 1] + T[M, R] + subproblem
// subproblem:
// num of pairs such that
// 1) .first from left part
// 2) .second from right part
// 1) i < R (OK)
// 2) nums[i] > 2*nums[R] (?)
// where i \in left part, R \in right part
// Result:
// T[0, n - 1]

// typedef long long ll;

// class Solution {
// private:
//     int n, result;
//     void mergeSortAndCount(vector<int> &nums, int start, int finish) {
//         if (start >= finish) { return; }
//         int mid = start + (finish - start) / 2;
        
//         // Trick: [s, mid], [mid + 1, finish]
//         // Check [0, 1] -> [0, 0], [1, 1]
//         // instead of [0, 1] -> [0, -1], [0, 1]
//         // using [s, mid - 1], [mid, f]
//         mergeSortAndCount(nums, start, mid);
//         mergeSortAndCount(nums, mid + 1, finish);
//         merge(nums, start, mid + 1, finish);
//     }
//     void merge(vector<int> &nums, int start, int mid, int finish) {
//         // start, mid - 1
//         // mid, finish
        
//         // Hack:
//         // For each element from the left list count
//         // num of els from the right list such that
//         // nums[L] > 2 * nums[R]
//         // Use 2 pointers since both lists are sorted.
//         // 4 7 12 24
//         // 1 5 8
//         int pL = start, pR = mid;
//         while (pL < mid && pR <= finish) {
//             ll num = 2LL * nums[pR];
//             if (nums[pL] > num) {
//                 result += mid - pL;
//                 pR += 1;
//             } else {
//                 pL += 1;
//             }
//         }
        
//         vector<int> temp(nums.begin() + start, nums.begin() + mid);
//         int idx_to_write = start;
//         int L1 = 0, L2 = mid;
//         while (L1 < (int)temp.size() && L2 <= finish) {
//             if (temp[L1] < nums[L2]) {
//                 nums[idx_to_write++] = temp[L1++];
//             } else {
//                 nums[idx_to_write++] = nums[L2++];
//             }
//         }
//         while (L1 < (int)temp.size()) {
//             nums[idx_to_write++] = temp[L1++];
//         }
//         while (L2 <= finish) {
//             nums[idx_to_write++] = nums[L2++];
//         }
//     }
// public:
//     int reversePairs(vector<int> nums) {
//         if (nums.empty()) { return 0; }
//         n = (int)nums.size();
//         result = 0;
//         mergeSortAndCount(nums, 0, n - 1);
//         return result;
//     }
// };
// 192ms

// typedef long long ll;

// class Solution {
// private:
//     int n, result;
//     vector<int> buffer;
//     void mergeSortAndCount(vector<int> &nums, int start, int finish) {
//         if (start >= finish) { return; }
//         int mid = start + (finish - start) / 2;
        
//         // Trick: [s, mid], [mid + 1, finish]
//         // Check [0, 1] -> [0, 0], [1, 1]
//         // instead of [0, 1] -> [0, -1], [0, 1]
//         // using [s, mid - 1], [mid, f]
//         mergeSortAndCount(nums, start, mid);
//         mergeSortAndCount(nums, mid + 1, finish);
//         merge(nums, start, mid + 1, finish);
//     }
//     void merge(vector<int> &nums, int start, int mid, int finish) {
//         // start, mid - 1
//         // mid, finish
        
//         // Hack:
//         // For each element from the left list count
//         // num of els from the right list such that
//         // nums[L] > 2 * nums[R]
//         // Use 2 pointers since both lists are sorted.
//         // 4 7 12 24
//         // 1 5 8
//         int pL = start, pR = mid;
//         while (pL < mid && pR <= finish) {
//             ll num = 2LL * nums[pR];
//             if (nums[pL] > num) {
//                 result += mid - pL;
//                 pR += 1;
//             } else {
//                 pL += 1;
//             }
//         }
        
//         int buf_len = mid - start;
//         for (int idx = 0; idx < buf_len; ++idx) {
//             buffer[idx] = nums[idx + start];
//         }
//         int idx_to_write = start;
//         int L1 = 0, L2 = mid;
//         while (L1 < buf_len && L2 <= finish) {
//             if (buffer[L1] < nums[L2]) {
//                 nums[idx_to_write++] = buffer[L1++];
//             } else {
//                 nums[idx_to_write++] = nums[L2++];
//             }
//         }
//         while (L1 < buf_len) {
//             nums[idx_to_write++] = buffer[L1++];
//         }
//         while (L2 <= finish) {
//             nums[idx_to_write++] = nums[L2++];
//         }
//     }
// public:
//     int reversePairs(vector<int> nums) {
//         if (nums.empty()) { return 0; }
//         n = (int)nums.size();
//         buffer.resize(n);
//         result = 0;
//         mergeSortAndCount(nums, 0, n - 1);
//         return result;
//     }
// };
// 175ms

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(2, sol.reversePairs({1,3,2,3,1}));
    EXPECT_EQ(3, sol.reversePairs({2,4,3,5,1}));
    EXPECT_EQ(4, sol.reversePairs({5,4,3,2,1}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

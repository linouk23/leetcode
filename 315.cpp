// 315. Count of Smaller Numbers After Self - https://leetcode.com/problems/count-of-smaller-numbers-after-self

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Part:
// T[L, R] = T[L, M - 1] + T[M, R] + subproblem
// subproblem:
// num of pairs such that
// 1) .first from left part
// 2) .second from right part
// 1) i < R (OK)
// 2) nums[i] > nums[R] (?)
// where i \in left part, R \in right part
// Result:
// T[0, n - 1]

//class Solution {
//private:
//    int n;
//    vector<int> result;
//    void mergeSortAndCount(vector<pair<int, int>> &nums, int L, int R) {
//        if (L >= R) { return; }
//        int M = L + (R - L) / 2;
//        // Check [0, 1] -> [0, 1), [1]
//        mergeSortAndCount(nums, L, M);
//        mergeSortAndCount(nums, M + 1, R);
//        merge(nums, L, M + 1, R);
//    }
//    void merge(vector<pair<int, int>> &nums, int L, int M, int R) {
//        // [L, M), [M, R]
//        vector<pair<int, int>> buffer(nums.begin() + L, nums.begin() + M);
//        int L1 = 0, L2 = M, idx_to_write = L;
//        int buf_len = M - L;
//        // Count:
//        int P1 = buf_len - 1, P2 = R;
//        // 1 7 10
//        // 2 4 20
//        while (P1 >= 0 && P2 >= M) {
//            if (buffer[P1] <= nums[P2]) {
//                --P2;
//            } else {
//                int init_idx = buffer[P1].second;
//                result[init_idx] += P2 - M + 1;
//                --P1;
//            }
//        }
//        
//        // Merge
//        // Trick: Use pair as int
//        while (L1 < buf_len && L2 <= R) {
//            if (buffer[L1] < nums[L2]) {
//                nums[idx_to_write++] = buffer[L1++];
//            } else {
//                nums[idx_to_write++] = nums[L2++];
//            }
//        }
//        while (L1 < buf_len) {
//            nums[idx_to_write++] = buffer[L1++];
//        }
//        while (L2 <= R) {
//            nums[idx_to_write++] = nums[L2++];
//        }
//    }
//public:
//    vector<int> countSmaller(vector<int> nums) {
//        n = (int)nums.size();
//        result.resize(n, 0);
//        vector<pair<int, int>> numsidx;
//        for (int idx = 0; idx < n; ++idx) {
//            numsidx.emplace_back(nums[idx], idx);
//        }
//        mergeSortAndCount(numsidx, 0, n - 1);
//        return result;
//    }
//};
//36ms

//class Solution {
//private:
//    int n;
//    vector<int> result;
//    vector<pair<int, int>> buffer;
//    void mergeSortAndCount(vector<pair<int, int>> &nums, int L, int R) {
//        if (L >= R) { return; }
//        int M = L + (R - L) / 2;
//        // Check [0, 1] -> [0, 1), [1]
//        mergeSortAndCount(nums, L, M);
//        mergeSortAndCount(nums, M + 1, R);
//        merge(nums, L, M + 1, R);
//    }
//    void merge(vector<pair<int, int>> &nums, int L, int M, int R) {
//        // [L, M), [M, R]
//        int L1 = 0, L2 = M, idx_to_write = L;
//        int buf_len = M - L;
//        for (int idx = 0; idx < buf_len; ++idx) {
//            buffer[idx] = nums[idx + L];
//        }
//        //vector<pair<int, int>> buffer(nums.begin() + L, nums.begin() + M);
//        // Count:
//        int P1 = buf_len - 1, P2 = R;
//        // 1 7 10
//        // 2 4 20
//        while (P1 >= 0 && P2 >= M) {
//            if (buffer[P1] <= nums[P2]) {
//                --P2;
//            } else {
//                int init_idx = buffer[P1].second;
//                result[init_idx] += P2 - M + 1;
//                --P1;
//            }
//        }
//        
//        // Merge
//        // Trick: Use pair as int
//        while (L1 < buf_len && L2 <= R) {
//            if (buffer[L1] < nums[L2]) {
//                nums[idx_to_write++] = buffer[L1++];
//            } else {
//                nums[idx_to_write++] = nums[L2++];
//            }
//        }
//        while (L1 < buf_len) {
//            nums[idx_to_write++] = buffer[L1++];
//        }
//        while (L2 <= R) {
//            nums[idx_to_write++] = nums[L2++];
//        }
//    }
//public:
//    vector<int> countSmaller(vector<int> nums) {
//        n = (int)nums.size();
//        result.resize(n, 0);
//        buffer.resize(n);
//        vector<pair<int, int>> numsidx;
//        for (int idx = 0; idx < n; ++idx) {
//            numsidx.emplace_back(nums[idx], idx);
//        }
//        mergeSortAndCount(numsidx, 0, n - 1);
//        return result;
//    }
//};
// 33ms

// Seq:
// T[L, R] = T[L, R - 1] + subproblem
// T[L, n - 1] = T[L + 1, n - 1] + subproblem
// subproblem:
// num of pairs such that
// 1) L < i (OK)
// 2) nums[L] > nums[i] (?)
// where i \in [L + 1, n - 1]
// Result:
// T[0, n - 1]

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
    int countInST(const SegmentTree& tree, int finish) {
        return tree.sum(0, finish);
    }
    int bs(const vector<pair<int, int>> &v, int num) {
        int L = -1;
        int R = (int)v.size();
        while (R - L > 1) {
            int M = L + (R - L) / 2;
            if (num > v[M].first) {
                L = M;
            } else {
                R = M;
            }
        }
        return L;
    }
public:
    vector<int> countSmaller(vector<int> nums) {
        int n = (int)nums.size();
        vector<int> result(n, 0);
        SegmentTree tree(result);
        unordered_map<int, int> idx_to_sorted_idx;
        vector<pair<int, int>> numsidx;
        for (int idx = 0; idx < n; ++idx) {
            numsidx.emplace_back(nums[idx], idx);
        }
        sort(numsidx.begin(), numsidx.end());
        for (int idx = n - 1; idx >= 0; --idx) {
            int init_idx = numsidx[idx].second;
            idx_to_sorted_idx[init_idx] = idx;
        }
        for (int idx = n - 1; idx >= 0; --idx) {
            int num = nums[idx];
            int finish = bs(numsidx, num);
            result[idx] = countInST(tree, finish);
            
            int sorted_idx = idx_to_sorted_idx[idx];
            tree.update(sorted_idx, 1);
        }
        return result;
    }
};
//42ms

TEST(SolutionTest, Small) {
    Solution sol;
    vector<int> expected = {2, 1, 1, 0};
    EXPECT_EQ(expected, sol.countSmaller({5,2,6,1}));
    expected = {0, 0};
    EXPECT_EQ(expected, sol.countSmaller({-1, -1}));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

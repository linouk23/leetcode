// 220. Contains Duplicate III - https://leetcode.com/problems/contains-duplicate-iii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

typedef long long ll;

// Idea:
// The idea is like the bucket sort algorithm.
// Suppose we have consecutive buckets covering the range
// of nums with each bucket a width of (t+1). If there are
// two item with difference <= t, one of the two will happen:
// (1) the two in the same bucket
// (2) the two in neighbor buckets.
class Solution {
private:
    long long getIdx(long long n, long long w) {
        // w = 5, n = 0,1,2,3,4 -> #0
        // n = -1,-2,-3,-4,-5 -> #-1
        return n < 0 ? ((n + 1) / w - 1) : n / w;
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int> nums, int k, int t) {
        if (t < 0) { return false; }
        // bucket_idx - idx
        unordered_map<ll, ll> hashtable;
        ll tt = (ll)t;
        ll kk = (ll)k;
        ll w = tt + 1;
        ll n = (ll)nums.size();
        for (ll idx = 0; idx < n; ++idx) {
            ll num = (ll)nums[idx];
            ll bucket_idx = getIdx(num, w);

            if (hashtable.count(bucket_idx)) { return true; }
            if (hashtable.count(bucket_idx - 1) &&
                abs(hashtable[bucket_idx - 1] - num) <= tt) { return true; }
            if (hashtable.count(bucket_idx + 1) &&
                abs(hashtable[bucket_idx + 1] - num) <= tt) { return true; }
            hashtable[bucket_idx] = num;
            
            if (idx < kk) { continue; }
            ll old_num = nums[idx - kk];
            ll old_bucket_idx = getIdx(old_num, w);
            // Trick.
            hashtable.erase(old_bucket_idx);
        }
        return false;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_FALSE(sol.containsNearbyAlmostDuplicate({-3,3}, 2, 4));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

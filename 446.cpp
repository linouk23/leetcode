// 446. Arithmetic Slices II - Subsequence - https://leetcode.com/problems/arithmetic-slices-ii-subsequence

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

struct Pair {
    ll idx, diff;
    bool operator==(const Pair &that) const {
        return that.idx == idx && that.diff == diff;
    }
};
namespace std {
    template <>
    struct hash<Pair> {
        size_t operator () (const Pair &p) const {
            return (std::hash<ll>()(p.idx) << 1) ^ std::hash<ll>()(p.diff);
        }
    };
}

// TLE
//class Solution {
//public:
//    int numberOfArithmeticSlices(vector<int> A) {
//        // Let dp[i][j] be the number of arithmetic slices
//        // which is ending at element with index i and
//        // diff between elements in AS is j: as[k] - as[k - 1] = j
//        // len(AS) >= 3
//        unordered_map<Pair, int> dp;
//        
//        // Kinda dp[i][j] for len(AS) = 2
//        // (index, diff) -> num of k (AS) : arr[index] - arr[k] = diff
//        unordered_map<Pair, int> dp_pair;
//        int n = (int)A.size();
//        for (int finish = 1; finish < n; ++finish) {
//            for (int start =  0; start < finish; ++start) {
//                ll diff = 1LL * A[finish] - 1LL * A[start];
//                if (diff > INT_MAX || diff < INT_MIN) continue;
//                dp_pair[{finish, diff}] += 1;
//            }
//        }
//        for (int last = 2; last < n; ++last) {
//            for (int snd_last = 1; snd_last < last; ++snd_last) {
//                ll diff = 1LL * A[last] - 1LL * A[snd_last];
//                if (diff > INT_MAX || diff < INT_MIN) continue;
//                // Len(AS) = 3
//                dp[{last, diff}] += dp_pair[{snd_last, diff}];
//                
//                // Len(AS) > 3
//                dp[{last, diff}] += dp[{snd_last, diff}];
//            }
//        }
//        int result = 0;
//        for (const auto &p : dp) {
//            result += p.second;
//        }
//        return result;
//    }
//};

//class Solution {
//public:
//    int numberOfArithmeticSlices(vector<int> A) {
//        // Let dp[i][j] be the number of arithmetic slices
//        // which is ending at element with index i and
//        // diff between elements in AS is j: as[k] - as[k - 1] = j
//        // len(AS) >= 3
//        int n = (int)A.size();
//        // Trick.
//        vector<unordered_map<int, int> > dp(n);
//        
//        // Kinda dp[i][j] for len(AS) = 2
//        // (index, diff) -> num of k (AS) : arr[index] - arr[k] = diff
//        vector<unordered_map<int, int> > dp_pair(n);
//        
//        for (int finish = 1; finish < n; ++finish) {
//            for (int start =  0; start < finish; ++start) {
//                ll diff = 1LL * A[finish] - 1LL * A[start];
//                if (diff > INT_MAX || diff < INT_MIN) continue;
//                dp_pair[finish][(int)diff] += 1;
//            }
//        }
//        for (int last = 2; last < n; ++last) {
//            for (int snd_last = 1; snd_last < last; ++snd_last) {
//                ll diff = 1LL * A[last] - 1LL * A[snd_last];
//                if (diff > INT_MAX || diff < INT_MIN) continue;
//                if (dp_pair[snd_last].count((int)diff)) {
//                    // Len(AS) = 3
//                    dp[last][(int)diff] += dp_pair[snd_last][(int)diff];
//                }
//                
//                if (dp[snd_last].count((int)diff)) {
//                    // Len(AS) > 3
//                    dp[last][(int)diff] += dp[snd_last][(int)diff];
//                }
//            }
//        }
//        int result = 0;
//        for (int idx = 0; idx < n; ++idx) {
//            for (const auto &p : dp[idx]) {
//                result += p.second;
//            }
//        }
//        return result;
//    }
//};

// 495ms -> 402ms

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> A) {
        // Let dp[i][j] be the number of arithmetic slices
        // which is ending at element with index i and
        // diff between elements in AS is j: as[k] - as[k - 1] = j
        // len(AS) >= 2!
        int n = (int)A.size();
        // Trick.
        vector<unordered_map<int, int> > dp(n);

        int result = 0;
        
        for (int last = 1; last < n; ++last) {
            for (int snd_last = 0; snd_last < last; ++snd_last) {
                ll diff = 1LL * A[last] - 1LL * A[snd_last];
                if (diff > INT_MAX || diff < INT_MIN) continue;
                dp[last][(int)diff] += 1;

                if (dp[snd_last].count((int)diff)) {
                    // Len(AS) > 3
                    dp[last][(int)diff] += dp[snd_last][(int)diff];
                    // Trick
                    result += dp[snd_last][(int)diff];
                }
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

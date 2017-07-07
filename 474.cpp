// 474. Ones and Zeroes - https://leetcode.com/problems/ones-and-zeroes

#include "bits/stdc++.h"

using namespace std;

struct Pair {
    int num_of_zeroes, num_of_ones;
};

class Solution {
private:
    int len;
    unordered_map<string, Pair> hashtable;
public:
    int findMaxForm(vector<string> strs, int m, int n) {
        const int MAXN = 105;
        const int MAXM = 150;
        array<array<int, MAXN>, MAXM> prev;
        auto cur = prev;
        int mm = 0;
        int nn = 0;
        const int len = (int)strs.size();
        for (const string &str : strs) {
            int num_of_ones = 0;
            for (int idx = 0; idx < (int)str.length(); ++idx) {
                if (str[idx] == '1') { ++num_of_ones; }
            }
            hashtable[str] = {(int)str.length() - num_of_ones, num_of_ones};
            mm += hashtable[str].num_of_zeroes;
            nn += hashtable[str].num_of_ones;
        }
        m = min(mm, m); n = min(nn, n);
        
        for (int num_of_zeroes = 0; num_of_zeroes <= m; ++num_of_zeroes) {
            for (int num_of_ones = 0; num_of_ones <= n; ++num_of_ones) {
                prev[num_of_zeroes][num_of_ones] = 0;
            }
        }
        // Trick.
        // cur = dp[k], prev = dp[k - 1].
        // Let dp[k][m][n] be the max number of strings which can be taken
        // from the array such that their:
        // 1) sum of zeroes <= m,
        // 2) sum of zeroes <= n,
        // 0-1 knapsack.
        // dp[k][m][n] = max(skip:dp[k - 1][m][n],
        //                   take:dp[k - 1][m - zeroes_in_str_k][ones_in_str_k]
        // For the first k strings that we've seen so far:
        for (int k = 1; k <= len; ++k) {
            for (int zeroes = 0; zeroes <= m; ++zeroes) {
                for (int ones = 0; ones <= n; ++ones) {
                    int zeroes_in_cur = hashtable[strs[k - 1]].num_of_zeroes;
                    int ones_in_cur = hashtable[strs[k - 1]].num_of_ones;
                    
                    // Skip current str
                    cur[zeroes][ones] = prev[zeroes][ones];
                    
                    // Take current str (if it's better)
                    if (zeroes < zeroes_in_cur || ones < ones_in_cur) { continue; }
                    cur[zeroes][ones] = max(
                            cur[zeroes][ones],
                            prev[zeroes - zeroes_in_cur][ones-ones_in_cur] + 1
                    );
                }
            }
            prev = cur;
        }
        int result = cur[m][n];
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

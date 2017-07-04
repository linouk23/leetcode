// 97. Interleaving String - https://leetcode.com/problems/interleaving-string

#include "bits/stdc++.h"

using namespace std;

struct Pair {
    int row, col;
    bool operator==(const Pair &that) const {
        return that.row == row && that.col == col;
    }
};
namespace std {
    template <>
    struct hash<Pair> {
        size_t operator () (const Pair &p) const {
            return (std::hash<int>()(p.row) << 1) ^ std::hash<int>()(p.col);
        }
    };
}

//class Solution {
//private:
//    string s1_, s2_, s3_;
//    unordered_set<Pair> visited;
//    bool helper(int L1, int L2) {
//        visited.insert({L1, L2});
//        int idx = L1 + L2;
//        
//        if (L1  > (int)s1_.length()) { return false; }
//        if (L2  > (int)s2_.length()) { return false; }
//        
//        if (idx == (int)s3_.length()) { return true; }
//        
//        if (s3_[idx] == s1_[L1]) {
//            if (!visited.count({L1 + 1, L2}) && helper(L1 + 1, L2)) { return true; }
//        }
//        if (s3_[idx] == s2_[L2]) {
//            if (!visited.count({L1, L2 + 1}) && helper(L1, L2 + 1)) { return true; }
//        }
//        
//        return false;
//    }
//public:
//    bool isInterleave(string s1, string s2, string s3) {
//        s1_ = s1; s2_ = s2; s3_ = s3;
//        if (s1.length() + s2.length() != s3.length()) {
//            return false;
//        }
//        return helper(0, 0);
//    }
//};

//class Solution {
//public:
//    bool isInterleave(string s1, string s2, string s3) {
//        if (s1.length() + s2.length() != s3.length()) {
//            return false;
//        }
//        stack<Pair> st;
//        st.push({0, 0});
//        unordered_set<Pair> visited;
//        while(!st.empty()) {
//            auto p = st.top(); st.pop();
//            if (visited.count(p)) { continue; }
//            visited.insert(p);
//            int idx = p.row + p.col;
//            if (idx == (int)s3.length()) { return true;  }
//            if (p.row > (int)s1.length()){ return false; }
//            if (p.col > (int)s2.length()){ return false; }
//            
//            if (s3[idx] == s1[p.row]) {
//                st.push({p.row + 1, p.col});
//            }
//            if (s3[idx] == s2[p.col]) {
//                st.push({p.row, p.col + 1});
//            }
//        }
//        return false;
//    }
//};

//class Solution {
//public:
//    bool isInterleave(string s1, string s2, string s3) {
//        if (s1.length() + s2.length() != s3.length()) {
//            return false;
//        }
//        queue<Pair> q;
//        q.push({0, 0});
//        unordered_set<Pair> visited;
//        while(!q.empty()) {
//            auto p = q.front(); q.pop();
//            if (visited.count(p)) { continue; }
//            visited.insert(p);
//            int idx = p.row + p.col;
//            if (idx == (int)s3.length()) { return true;  }
//            if (p.row > (int)s1.length()){ return false; }
//            if (p.col > (int)s2.length()){ return false; }
//            
//            if (s3[idx] == s1[p.row]) {
//                q.push({p.row + 1, p.col});
//            }
//            if (s3[idx] == s2[p.col]) {
//                q.push({p.row, p.col + 1});
//            }
//        }
//        return false;
//    }
//};


// BFS, DFS -> Table -> DP (path from top L to bottom R)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        int n = (int)s1.length();
        int m = (int)s2.length();
        vector<vector<bool> > dp(n + 1, vector<bool> (m + 1, false));
        dp[0][0] = true;
        for (int col = 1; col <= m; ++col) {
            dp[0][col] = dp[0][col - 1] && (s3[col - 1] == s2[col - 1]);
        }
        for (int row = 1; row <= n; ++row) {
            dp[row][0] = dp[row - 1][0] && (s3[row - 1] == s1[row - 1]);
        }
        for (int row = 1; row <= n; ++row) {
            for (int col = 1; col <= m; ++col) {
                int idx = row + col;
                if (s3[idx - 1] == s1[row - 1]) {
                    dp[row][col] = dp[row][col] || dp[row - 1][col];
                }
                if (s3[idx - 1] == s2[col - 1]) {
                    dp[row][col] = dp[row][col] || dp[row][col - 1];
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

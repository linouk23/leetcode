// 306. Additive Number - https://leetcode.com/problems/additive-number

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    int n;
    string str;
    string sum(const string & s, const string & t) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string rev_t = t;
        reverse(rev_t.begin(), rev_t.end());
        string result = "";
        int rem = 0;
        for (int idx = 0; idx < max(rev_s.length(), rev_t.length()); ++idx) {
            int dig_s = (idx < rev_s.length() ? rev_s[idx] - '0' : 0);
            int dig_t = (idx < rev_t.length() ? rev_t[idx] - '0' : 0);
            int sum = dig_s + dig_t + rem;
            result.push_back('0' + (sum % 10));
            rem = sum / 10;
        }
        if (rem) {
            result.push_back('0' + rem);
        }
        return {result.rbegin(), result.rend()};
    }
    
    // start
    // |
    // v
    // w1|w2
    bool check(int start, const string & w1, const string & w2) {
        // Check leading zeroes.
        if ((w1.length() > 1 && w1[0] == '0') ||
           (w2.length() > 1 && w2[0] == '0')) {
            return false;
        }
        
        int pos = start + (int)w1.length() + (int)w2.length();
        string result = sum(w1, w2);
        if (result != str.substr(pos, result.length())) {
            return false;
        }
        if (pos + (int)result.length() == n) {
            return true;
        }
        return check(start + (int)w1.length(), w2, result);
    }
public:
    bool isAdditiveNumber(string num) {
        n = (int)num.length();
        if (n < 3) { return false; }
        str = num;
        for (int len1 = 1; len1 < n; ++len1) {
            for (int len2 = 1; len1 + len2 < n; ++len2) {
                string w1 = num.substr(0, len1);
                string w2 = num.substr(len1, len2);
                if (check(0, w1, w2)) { return true; }
            }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

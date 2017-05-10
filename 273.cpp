// 273. Integer to English Words - https://leetcode.com/problems/integer-to-english-words

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    vector<string> bTen = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> bTwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> bHundred = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string trim(const string &str) {
        int L = 0;
        int R = (int)str.length() - 1;
        while (L <= R && str[L] == ' ') {
            ++L;
        }
        while (R >= 0 && str[R] == ' ') {
            --R;
        }
        return string(str.begin() + L, str.begin() + R + 1);
    }
    
    string helper(int n) {
        string result;
        if (n < 10) { return bTen[n]; }
        else if (n < 20) { return bTwenty[n - 10]; }
        else if (n < 1e2) {
            result = bHundred[n / 10] + " " + helper(n % (int)1e1);
        }
        else if (n < 1e3) {
            result =  bTen[n / 1e2] + " Hundred " + helper(n % (int)1e2);
        } else if (n < 1e6) {
            result =  helper(n / 1e3) + " Thousand " + helper(n % (int)1e3);
        } else if (n < 1e9) {
            result =  helper(n / 1e6) + " Million " + helper(n % (int)1e6);
        } else if (n < 1e12) {
            result =  helper(n / 1e9) + " Billion " + helper(n % (int)1e9);
        }
        return trim(result);
    }
    
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return helper(num);
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

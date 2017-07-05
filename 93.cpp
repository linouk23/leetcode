// 93. Restore IP Addresses - https://leetcode.com/problems/restore-ip-addresses

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    vector<vector<int> > result;
    bool is_valid_octet(const string & str) {
        int n = (int)str.length();
        if (n == 1) { return true; }
        if (n == 0 || n >= 4) { return false; }
        return str[0] != '0' && stoi(str) < 256;
    }
    void dfs(int start, int num_of_dots_left, const string & str, vector<int> lens) {
        if (num_of_dots_left == 0) {
            string last_octet = str.substr(start);
            if (is_valid_octet(last_octet)) {
                result.emplace_back(lens);
            }
            return;
        }
        int n = (int)str.length();
        for (int len_of_octet = 1; len_of_octet <= 3; ++len_of_octet) {
            if (start + len_of_octet >= n) { break; }
            string octet = str.substr(start, len_of_octet);
            if (is_valid_octet(octet)) {
                lens.emplace_back(len_of_octet);
                dfs(start + len_of_octet, num_of_dots_left - 1, str, lens);
                lens.pop_back();
            }
        }
    }
    vector<string> generate_result(const string &s) {
        vector<string> ips;
        string delim = ".";
        for (const auto & len : result) {
            string ip = s.substr(0, len[0]) + delim +
                        s.substr(len[0], len[1]) + delim +
                        s.substr(len[0] + len[1], len[2]) + delim +
                        s.substr(len[0] + len[1] + len[2]);
            ips.emplace_back(ip);
        }
        return ips;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(0, 3, s, {});
        return generate_result(s);
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 468. Validate IP Address - https://leetcode.com/problems/validate-ip-address

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    char delim4 = '.';
    char delim6 = ':';
    const string validIPv6Chars = "0123456789abcdefABCDEF";
    bool isValidIPv4Block(const string& block) {
        if (block.empty() > 0 || block.size() > 3) {
            return false;
        }
        int num = 0;
        for (int idx = 0; idx < (int)block.size(); ++idx) {
            char ch = block[idx];
            if (!isalnum(ch) || (idx == 0 && ch == '0' && (int)block.size() > 1))
                return false;
            else {
                num *= 10;
                num += ch - '0';
            }
        }
        return num <= 255;
    }
    
    bool isValidIPv6Block(const string& block) {
        if (block.empty() || block.size() > 4) {
            return false;
        }
        
        for (char ch : block) {
            if (validIPv6Chars.find(ch) == string::npos)
                return false;
        }
        return true;
    }
public:
    string validIPAddress(string IP) {
        vector<string> result = {"IPv4", "IPv6", "Neither"};
        stringstream ss(IP);
        string block;
        // a) IPv4
        if (IP.substr(0, 4).find(delim4) != string::npos) {
            for (int idx = 0; idx < 4; ++idx) {
                if (!getline(ss, block, delim4) || !isValidIPv4Block(block))
                    return result[2];
            }
            return ss.eof() ? result[0] : result[2];
        // b) IPv6
        } else if (IP.substr(0, 5).find(delim6) != string::npos) {
            for (int idx = 0; idx < 8; ++idx) {
                if (!getline(ss, block, delim6) || !isValidIPv6Block(block))
                    return result[2];
            }
            return ss.eof() ? result[1] : result[2];
        }
        return result[2];
    }
};

int main() {
    ios::sync_with_stdio(false);
    Solution sol;
    sol.solveEquation("x+5-3+x=6+x-2");
    return 0;
}

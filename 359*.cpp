// 359. Logger Rate Limiter - https://leetcode.com/problems/logger-rate-limiter

#include "bits/stdc++.h"

using namespace std;

class Logger {
public:
    // Default value is 0
    map<string, int> ok;
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp < ok[message]) { return false; }
        ok[message] = timestamp + 10;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

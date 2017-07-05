// 393. UTF-8 Validation - https://leetcode.com/problems/utf-8-validation

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int bytes_left = 0;
        for (auto c : data) {
            if (bytes_left == 0) {
                if ((c >> 5) == 0b110)       { bytes_left = 1; }
                else if ((c >> 4) == 0b1110) { bytes_left = 2; }
                else if ((c >> 3) == 0b11110){ bytes_left = 3; }
                // For 1-byte character, the first bit is a 0,
                // followed by its unicode code.
                else if ((c >> 7))           { return false;   }
            } else {
                // Followed by n-1 bytes with most significant
                // 2 bits being 10.
                if ((c >> 6) != 0b10)        { return false;   }
                bytes_left--;
            }
        }
        return bytes_left == 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

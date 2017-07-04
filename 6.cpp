// 6. ZigZag Conversion - https://leetcode.com/problems/zigzag-conversion

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;
        
        const int len = (int)s.length();
        vector<string> str(numRows);
        
        int row = 0, step = 1;
        for (int idx = 0; idx < len; ++idx)
        {
            str[row].push_back(s[idx]);
            
            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;
            
            row += step;
        }
        
        s.clear();
        for (int idx = 0; idx < numRows; ++idx) {
            s.append(str[idx]);
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

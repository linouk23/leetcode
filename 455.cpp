// 455. Assign Cookies - https://leetcode.com/problems/assign-cookies

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0;
        for (int index = 0; result < (int)g.size() && index < (int)s.size(); ++index) {
            if (g[result] <= s[index]) { ++result; }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

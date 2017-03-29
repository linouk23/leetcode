// 434. Number of Segments in a String - https://leetcode.com/problems/number-of-segments-in-a-string

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int left = 0;
        int right = s.length() - 1;
        while(left <= right && s[left] == ' ') {
            ++left;
        }
        while(right >= left && s[right] == ' ') {
            --right;
        }
        if (left > right) { return 0; }
        int num_of_whitespaces = 0;
        while(left <= right) {
            if (s[left] == ' ') {
                ++num_of_whitespaces;
            }
            while(left <= right && s[left] == ' ') {
                ++left;
            }
            ++left;
        }
        return num_of_whitespaces + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.countSegments(" Hello, my name is John") == 5);
    assert(solution.countSegments("John") == 1);
    assert(solution.countSegments(" Hello, my ") == 2);
    assert(solution.countSegments("") == 0);

    return 0;
}

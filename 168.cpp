// 168. Excel Sheet Column Title - https://leetcode.com/problems/excel-sheet-column-title

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string answer = "";
        while(n > 0) {
            --n;
            char ch = (n % 26) + 'A';
            answer += ch;
            n /= 26;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.convertToTitle(1) == "A");
    assert(solution.convertToTitle(26) == "Z");
    assert(solution.convertToTitle(27) == "AA");
    assert(solution.convertToTitle(28) == "AB");

    return 0;
}

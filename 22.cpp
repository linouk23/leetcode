// 22. Generate Parentheses - https://leetcode.com/problems/generate-parentheses

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    vector<string> result;
    
    void helper(int left_paren_left, int right_paren_left, string combination = "") {
        if (left_paren_left > right_paren_left) { return; }
        if (left_paren_left < 0 ||  right_paren_left < 0) { return; }
        if (left_paren_left == right_paren_left && left_paren_left == 0) {
            result.emplace_back(combination);
        }
        
        combination.append("(");
        helper(left_paren_left - 1, right_paren_left, combination);
        combination.pop_back();
        combination.append(")");
        helper(left_paren_left, right_paren_left - 1, combination);
    }
public:
    vector<string> generateParenthesis(int n) {
        helper(n, n);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}

// 301. Remove Invalid Parentheses - https://leetcode.com/problems/remove-invalid-parentheses

#include "bits/stdc++.h"

using namespace std;

class Solution {
private:
    unordered_set<string> result, visited;
    
    bool is_valid(string &str) {
        int count = 0;
        for (char ch : str) {
            if (ch == '(') { ++count; }
            else if (ch == ')') { --count; }
            if (count < 0) { return false; }
        }
        return count == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        // For a string of parentheses to be valid,
        // its number of parentheses should be even.
        // And at any time, strings in queue will only
        // differ in length of 1 (this is the implicit control).
        // When we find "()()" to be valid, both "()" and "" have
        // not been added to queue yet and all the shorter strings
        // are of length of 3, which must be invalid.
        
        set<char> parens = { '(', ')' };
        queue<string> q;
        q.push(s);
        visited.insert(s);
        bool has_found = false;
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            
            // Valid
            if (is_valid(cur)) {
                result.insert(cur);
                has_found = true;
            }
            
            // Stop cause we're interested in min number of deletions.
            if (has_found) {
                continue;
            }
            
            // Not Valid
            for (int index = 0; index < cur.length(); ++index) {
                char ch = cur[index];
                if (!parens.count(ch)) { continue; }
                string modified = cur.substr(0, index) + cur.substr(index + 1);
                if (visited.count(modified)) { continue; }
                visited.insert(modified);
                q.push(modified);
            }
        }
        return {result.begin(), result.end()};
    }
};


int main() {
    ios::sync_with_stdio(false);
    return 0;
}

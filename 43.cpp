// 43. Multiply Strings - https://leetcode.com/problems/multiply-strings

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = (int)num1.length(); int m = (int)num2.length();
        vector<int> result(n + m, 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                result[i + j] += result[i + j + 1] / 10;
                result[i + j + 1] %= 10;
            }
        }
        
        result = {
            find_if_not(begin(result), end(result), [](int a) { return a == 0; }),
            end(result)
        };
        
        if (result.empty()) {
            return "0";
        }
        
        stringstream str_result;
        copy(result.begin(), result.end(), ostream_iterator<int>(str_result, ""));
        return str_result.str().c_str();
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    assert(solution.multiply("112399", "1239") == "139262361");
    assert(solution.multiply("01", "2") == "2");
    
    return 0;
}

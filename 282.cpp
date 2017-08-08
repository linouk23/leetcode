// 282. Expression Add Operators - https://leetcode.com/problems/expression-add-operators

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

typedef long long ll;

class Solution {
private:
    vector<string> result;
    void helper(const string& s, int start, ll target,
                string path_so_far, ll res_so_far, ll val_to_mult) {
        if (start == s.length()) {
            if (res_so_far == target) { result.push_back(path_so_far); }
            return;
        }
        
        // Construct a number from start position
        // to add to/subtract from/multiply by/ result
        for (int num_of_dig = 1; num_of_dig <= s.length(); ++num_of_dig) {
            int R = start + num_of_dig - 1;
            if (R >= s.length()) { break; }
            if (!isdigit(s[R]))  { break; }
            ll number = stoll(s.substr(start, num_of_dig));
            
            // Check leading zeroes:
            if (to_string(number).length() != num_of_dig) { continue; }
            
            // Try out +, - and *
            // 8+5*6 -> 13,5 -> 13-5+30=38
            helper(s, start + num_of_dig, target,
                   path_so_far + (start == 0 ? "" : "+") + to_string(number),
                   res_so_far + number, number);
            if (start == 0) { continue; }
            // 8-5*6 -> 3,5 -> 3-(-5)+(-5)*6=-22
            helper(s, start + num_of_dig, target,
                   path_so_far + "-" + to_string(number),
                   res_so_far - number, -number);
            // 2*3*4 -> 2,2 -> 2-2+2*3=6,6 -> 6-6+6*4=24
            helper(s, start + num_of_dig, target,
                   path_so_far + "*" + to_string(number),
                   res_so_far - val_to_mult + val_to_mult * number,
                   val_to_mult * number);
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        helper(num, 0, (ll)target, "", 0, 0);
        return result;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

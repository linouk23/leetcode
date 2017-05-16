// 537. Complex Number Multiplication - https://leetcode.com/problems/complex-number-multiplication

#include "bits/stdc++.h"

using namespace std;

// (a + bi)(c + di) = (ac - bd) + (ad + bc) * i

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int real_a, im_a, real_b, im_b;
        char buff;
        stringstream aa(a), bb(b);
        string result;
        aa >> real_a >> buff >> im_a >> buff;
        bb >> real_b >> buff >> im_b >> buff;
        result = to_string(real_a * real_b - im_a*im_b) + "+" +
                 to_string(real_a*im_b + real_b*im_a) + "i";
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
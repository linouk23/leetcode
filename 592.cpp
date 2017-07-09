// 592. Fraction Addition and Subtraction - https://leetcode.com/problems/fraction-addition-and-subtraction

#include "bits/stdc++.h"

using namespace std;

class Fraq {
private:
    char delim = '/';
    int num, den;
    int gcd(int a, int b) {
        if (b == 0) { return a; }
        return gcd(b, a % b);
    }
    void reduce() {
        int divisor = gcd(abs(num), abs(den));
        if (divisor == 1 || divisor == 0) { return; }
        num /= divisor;
        den /= divisor;
    }
    int lca(int a, int b) {
        return a * b / gcd(a, b);
    }
public:
    Fraq(const string &str) {
        string fraq[2];
        int start = 0;
        num = str[0] == '-' ? -1 : 1;
        if (str[0] == '+' || str[0] == '-') {
            ++start;
        }
        stringstream ss(str.substr(start));
        for (int idx = 0; idx < 2; ++idx) {
            getline(ss, fraq[idx], delim);
        }
        num = stoi(fraq[0]) * num;
        den = stoi(fraq[1]);
    }
    Fraq& operator+=(const Fraq& right) {
        int full_den = lca(den, right.den);
        int right_mult = full_den / right.den;
        int left_mult = full_den / den;
        
        this->den = full_den;
        this->num = left_mult * num;
        this->num += right_mult * right.num;
        reduce();
        return *this;
    }
    string get_string() {
        return to_string(num) + delim + to_string(den);
    }
};

class Solution {
public:
    string fractionAddition(string expression) {
        int start = 0;
        Fraq result("0/1");
        expression += "+";
        for (int idx = 1; idx < (int)expression.length(); ++idx) {
            if (expression[idx] == '+' ||
                expression[idx] == '-') {
                int len = idx - start;
                result += Fraq(expression.substr(start, len));
                start = idx;
            }
        }
        return result.get_string();
    }
};

// string fractionAddition(string expression) {
//     istringstream in(expression);
//     int A = 0, B = 1, a, b;
//     char _;
//     while (in >> a >> _ >> b) {
//         A = A * b + a * B;
//         B *= b;
//         int g = abs(__gcd(A, B));
//         A /= g;
//         B /= g;
//     }
//     return to_string(A) + '/' + to_string(B);
// }



int main() {
    ios::sync_with_stdio(false);
    return 0;
}

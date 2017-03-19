// 7. Reverse Integer - https://leetcode.com/problems/reverse-integer

#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    int reverse(int x) {
        bool is_negative = (x < 0);
        if (is_negative) {
            x = abs(x);
        }
        
        int reversed_num = 0;
        while(x) {
            if (reversed_num > INT_MAX / 10) {
                return 0;
            }

            reversed_num = 10 * reversed_num;
            if (reversed_num > INT_MAX - x % 10) {
                return 0;
            } 

            reversed_num += x % 10;
            x /= 10;
        }

        return (is_negative) ? -reversed_num : reversed_num;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.reverse(-123) == -321);
    assert(solution.reverse(1000) == 1);
    assert(solution.reverse(5555) == 5555);
    assert(solution.reverse(1000000009) == 0);

    return 0;
}

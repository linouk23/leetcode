// 202. Happy Number - https://leetcode.com/problems/happy-number

#include <bits/stdc++.h>

using namespace std;

int square_digit_sum(int n) {
    int sum = 0;
    while(n > 0) {
        int carry = n % 10;
        sum += carry * carry;
        n /= 10;
    }
    return sum;
}

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = square_digit_sum(slow);
            fast = square_digit_sum(square_digit_sum(fast));
            if (fast == 1) {
                return true;
            }
        } while(slow != fast);
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.isHappy(19) == true);
    assert(solution.isHappy(1) == true);
    assert(solution.isHappy(INT_MAX) == false);

    return 0;
}

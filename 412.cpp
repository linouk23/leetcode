// 412. Fizz Buzz - https://leetcode.com/problems/fizz-buzz

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for (int num = 1; num <= n; ++num) {
            if (num % 3 == 0) {
                if (num % 5 == 0) {
                    answer.push_back("FizzBuzz");
                } else {
                    answer.push_back("Fizz");
                }
            } else if (num % 5 == 0) {
                answer.push_back("Buzz");
            } else {
                answer.push_back(to_string(num));
            }
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<string> expected_ans = {
        "1",
        "2",
        "Fizz",
        "4",
        "Buzz",
        "Fizz",
        "7",
        "8",
        "Fizz",
        "Buzz",
        "11",
        "Fizz",
        "13",
        "14",
        "FizzBuzz"
    };

    assert(solution.fizzBuzz(15) == expected_ans);

    return 0;
}

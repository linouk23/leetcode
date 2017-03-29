// 401. Binary Watch - https://leetcode.com/problems/binary-watch

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for (int hours = 0; hours <= 11; ++hours) {
            for (int minutes = 0; minutes < 60; ++minutes) {
                if (bitset<10>((hours << 6) | minutes).count() == num) {
                    result.emplace_back(to_string(hours) + (minutes < 10 ? ":0" : ":") + to_string(minutes));
                }
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<string> expected_ans = {
        "0:01", "0:02", "0:04", "0:08",
        "0:16", "0:32",
        "1:00", "2:00", "4:00", "8:00",
    };
    assert(solution.readBinaryWatch(1) == expected_ans);

    return 0;
}

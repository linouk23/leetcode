// 551. Student Attendance Record I - https://leetcode.com/problems/student-attendance-record-i

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int absent_count = 0, late_conseq_count = 0;
        for (char status : s) {
            if (status == 'A') {
                ++absent_count;
            }
            if (status == 'L') {
                ++late_conseq_count;
            } else {
                late_conseq_count = 0;
            }
            if (absent_count >= 2 || late_conseq_count > 2) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
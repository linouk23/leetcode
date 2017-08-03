// 630. Course Schedule III - https://leetcode.com/problems/course-schedule-iii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;


// Trick: greedy.
// Sort all the courses by their ending time. When considering the
// first K courses, they all end before end. A necessary and sufficient
// condition for our schedule to be valid, is that (for all K), the courses
// we choose to take within the first K of them, have total duration less than end.
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const vector<int> &op1,
                const vector<int> &op2) { return op1[1] < op2[1]; }
        );
        priority_queue<int> max_heap;
        int start = 0;
        for (int idx = 0; idx < courses.size(); ++idx)
        {
            int len = courses[idx][0];
            max_heap.push(len);
            start += len;
            int end = courses[idx][1];
            if (start > end) {
                start -= max_heap.top();
                max_heap.pop();
            }
        }
        return (int)max_heap.size();
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

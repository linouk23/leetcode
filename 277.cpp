// 277. Find the Celebrity - https://leetcode.com/problems/find-the-celebrity

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for(int person = 1; person < n; ++person){
            // Case #1: cand knows person -> candidate cannot be celebrity,
            // person can be celebrity, so candidate = person.
            // Case #2: cand doesn't know person -> person cannot be celebrity,
            // candidate cab be celebrity, so go on.
            if (knows(candidate, person)) {
                candidate = person;
            }
        }
        for (int person = 0; person < n; ++person) {
            // Whether the candidate is real: check initial statements:
            // The definition of a celebrity is that:
            // all the other n - 1people know him/her but
            // he/she does not know any of them.
            if (person != candidate && (knows(candidate, person) ||
                !knows(person, candidate))) return -1;
        }
        return candidate;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

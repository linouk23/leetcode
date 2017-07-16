// 251. Flatten 2D Vector - https://leetcode.com/problems/flatten-2d-vector

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Vector2D {
private:
    vector<vector<int>>::iterator row, out_of_bounds;
    int col;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        col = 0;
        row = vec2d.begin();
        out_of_bounds = vec2d.end();
    }
    
    int next() {
        return (*row)[col++];
    }
    
    bool hasNext() {
        while (row != out_of_bounds && col == (*row).size()) {
            ++row;
            col = 0;
        }
        return row != out_of_bounds;
    }
};

TEST(SolutionTest, Small) {
    vector<vector<int>> vec2d = {
        {1,2},
        {3},
        {4,5,6},
    };
    vector<int> expected = {
        1, 2, 3, 4, 5, 6
    };
    Vector2D i(vec2d);
    int idx = 0;
    while (i.hasNext()) {
        EXPECT_EQ(i.next(), expected[idx]);
        ++idx;
    }
    EXPECT_EQ(6, idx);
    
    vec2d = {
        {}, {},
        {1,2},
        {3},
        {},
        {4,5,6},
        {},
    };
    expected = {
        1, 2, 3, 4, 5, 6
    };
    Vector2D i2(vec2d);
    idx = 0;
    while (i2.hasNext()) {
        EXPECT_EQ(i2.next(), expected[idx]);
        ++idx;
    }
    EXPECT_EQ(6, idx);
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

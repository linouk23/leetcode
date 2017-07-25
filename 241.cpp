// 241. Different Ways to Add Parentheses - https://leetcode.com/problems/different-ways-to-add-parentheses
#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

/*
// Phil Jackson rec.
class Solution {
private:
    string ops = "-+*";
public:
    vector<int> diffWaysToCompute(string input) {
        int n = (int)input.length();
        vector<int> result;
        for (int mid_idx = 0; mid_idx < n; ++mid_idx) {
            if (ops.find(input[mid_idx]) == string::npos) { continue; }
            auto left_results = diffWaysToCompute(input.substr(0, mid_idx));
            auto right_results = diffWaysToCompute(input.substr(mid_idx + 1));
            // Go through all the options.
            for (int lres : left_results) {
                for (int rres : right_results) {
                    switch (input[mid_idx]) {
                        case '+':
                            result.emplace_back(lres + rres);
                            break;
                        case '-':
                            result.emplace_back(lres - rres);
                            break;
                        case '*':
                            result.emplace_back(lres * rres);
                            break;
                    }
                }
            }
        }
        // (23)
        if (result.empty()) {
            result.emplace_back(stoi(input));
        }
        return result;
    }
};
*/

// Phil Jackson rec.
// Divide and conquer.
// class Solution {
// private:
//     string ops = "-+*";
//     unordered_map<string, vector<int>> cache;
//     vector<int> helper(const string &input) {
//         if (cache.count(input)) { return cache[input]; }
//         int n = (int)input.length();
//         vector<int> result;
//         for (int mid_idx = 0; mid_idx < n; ++mid_idx) {
//             if (ops.find(input[mid_idx]) == string::npos) { continue; }
//             auto left_results = helper(input.substr(0, mid_idx));
//             auto right_results = helper(input.substr(mid_idx + 1));
//             // Go through all the options.
//             for (int lres : left_results) {
//                 for (int rres : right_results) {
//                     switch (input[mid_idx]) {
//                         case '+':
//                             result.emplace_back(lres + rres);
//                             break;
//                         case '-':
//                             result.emplace_back(lres - rres);
//                             break;
//                         case '*':
//                             result.emplace_back(lres * rres);
//                             break;
//                     }
//                 }
//             }
//         }
//         // (23)
//         if (result.empty()) {
//             result.emplace_back(stoi(input));
//         }
//         cache[input] = result;
//         return result;
//     }
// public:
//     vector<int> diffWaysToCompute(string input) {
//         return helper(input);
//     }
// };

// Phil Jackson rec.
// Divide and conquer.
class Solution {
private:
    string ops = "-+*";
    unordered_map<string, vector<int>> cache;
public:
    vector<int> diffWaysToCompute(const string &input) {
        if (cache.count(input)) { return cache[input]; }
        int n = (int)input.length();
        vector<int> result;
        for (int mid_idx = 0; mid_idx < n; ++mid_idx) {
            if (ops.find(input[mid_idx]) == string::npos) { continue; }
            auto left_results = diffWaysToCompute(input.substr(0, mid_idx));
            auto right_results = diffWaysToCompute(input.substr(mid_idx + 1));
            // Go through all the options.
            for (int lres : left_results) {
                for (int rres : right_results) {
                    switch (input[mid_idx]) {
                        case '+':
                            result.emplace_back(lres + rres);
                            break;
                        case '-':
                            result.emplace_back(lres - rres);
                            break;
                        case '*':
                            result.emplace_back(lres * rres);
                            break;
                    }
                }
            }
        }
        // (23)
        if (result.empty()) {
            result.emplace_back(stoi(input));
        }
        cache[input] = result;
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    vector<int> expected = {2, 0};
    EXPECT_EQ(expected, sol.diffWaysToCompute("2-1-1"));
    expected = {-34, -10, -14, -10, 10};
    EXPECT_EQ(expected, sol.diffWaysToCompute("2*3-4*5"));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

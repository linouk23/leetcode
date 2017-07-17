// 388. Longest Absolute File Path - https://leetcode.com/problems/longest-absolute-file-path

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Idea: stack, pay attention that in String
// "\n", "\t", "\123" will all be count the length as one
class Solution {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        char delim = '\n';
        string path;
        // stores len of strings per level, used for counting total len
        // "" - 0
        // f01 - 0 + 2 = 3
        // \tf2 - 3 + 2 = 5
        // pop() -> get last len from prev level
        // \tff3 - 3 + 3 = 6
        // \t\tfile.txt -> f01 + ff3 + file.txt -> 6 + 8 = 14
        int result = 0;
        stack<int> st;
        st.push(0); // dummy len
        while (getline(ss, path, delim)) {
            // \t\t\tfolder_name -> level #3
            size_t level = path.find_last_of('\t') + 1;
            if (level == string::npos) { level = 0; }
            // int != -1
            
            // Find parent folder len
            while (st.size() > level + 1) { st.pop(); }
            
            // Remove '/t', add '/':
            // res: "dir/subdir2/subsubdir2/file2.ext"
            int prev_len = st.top();
            int cur_len = prev_len + (int)path.length() - (int)level+ 1;
            st.push(cur_len);
            if (path.find('.') != string::npos) {
                result = max(result, cur_len - 1);
            }
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1";
    input += "\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    EXPECT_EQ(32, sol.lengthLongestPath(input));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

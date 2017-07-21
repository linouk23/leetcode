// 271. Encode and Decode Strings - https://leetcode.com/problems/encode-and-decode-strings

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

// Idea: for each str in strs, encode it as <length> + '#' + str
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (string &str: strs) {
            int len = (int)str.size();
            encoded += to_string(len) + "#" + str;
        }
        
        return encoded;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int head = 0;
        int n = (int)s.length();
        while (head < n) {
            int delim_pos = (int)s.find_first_of('#', head);
            int len = stoi(s.substr(head, delim_pos - head));
            head = delim_pos + 1;
            result.emplace_back(s.substr(head, len));
            head += len;
        }
        
        return result;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

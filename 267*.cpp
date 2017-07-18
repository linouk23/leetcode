// 267. Palindrome Permutation II - https://leetcode.com/problems/palindrome-permutation-ii

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> result;
        unordered_map<char,int> hashtable;
        for (char ch : s) { hashtable[ch] += 1; }
        char oddChar = 'a';
        bool foundOddChar = false;
        string str = "";
        char ch; int count;
        for(const auto &p : hashtable){
            tie(ch, count) = p;
            str += string(count / 2, ch);
            if(count % 2){
                if (foundOddChar) { return result; }
                foundOddChar = true;
                oddChar = ch;
            }
        }
        // Odd symbol can be in the middle of any palindrome permutation only.
        string middle = !foundOddChar ? "" : string(1, oddChar);
        sort(str.begin(), str.end());
        do {
            // str + oddChar? + str.reversed()
            result.emplace_back(str+middle+string(str.rbegin(),str.rend()));
        } while (next_permutation(str.begin(), str.end()));
        
        return result;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

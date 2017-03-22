// 49. Group Anagrams - https://leetcode.com/problems/anagrams

#include <bits/stdc++.h>

using namespace std;

string count_sort(string str) {
    const int num_of_letters = 26;
    vector<int> alphabet(num_of_letters);
    for (char ch : str) {
        alphabet[ch - 'a'] += 1;
    }
    string res;
    for (int letter = 0; letter < num_of_letters; ++letter) {
        char ch = letter + 'a';
        for (int index = 0; index < alphabet[letter]; ++index) {
            res.push_back(ch);
        }
    }
    return res;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashtable;

        for (const auto &str : strs) {
            string key = count_sort(str);
            hashtable[key].emplace_back(str);
        }

        vector<vector<string>> answer;
        for (const auto &it : hashtable) {
            answer.push_back(it.second);
        }

        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> expected_ans = {
        {"bat"},
        {"tan", "nat"},
        {"eat", "tea", "ate"}
    };
    assert(solution.groupAnagrams(input) == expected_ans);

    return 0;
}

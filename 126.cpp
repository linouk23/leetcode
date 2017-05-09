// 126. Word Ladder II - https://leetcode.com/problems/word-ladder-ii

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void rec(vector<string> path, string endWord) {
        for (const auto &word : graph[endWord]) {
            if (distance[word] + 1 != distance[endWord]) { continue; }
            if (distance[word] == 1) {
                path.push_back(word);
                result_set.insert({path.rbegin(), path.rend()});
                return;
            } else {
                path.push_back(word);
                rec(path, word);
                path.pop_back();
            }
        }
    }
    
    bool has_edge(const string &str1, const string &str2) {
        bool has_diff = false;
        for (int i = 0; i < (int)str1.length(); ++i) {
            if (str1[i] == str2[i]) { continue; }
            if (!has_diff) {
                has_diff = true;
            } else {
                return false;
            }
        }
        return has_diff;
    }
    
    void build_graph(vector<string>& wordList) {
        for (int from = 0; from < (int)wordList.size(); ++from) {
            for (int to = from + 1; to < (int)wordList.size(); ++to) {
                if (has_edge(wordList[from], wordList[to])) {
                    graph[wordList[from]].push_back(wordList[to]);
                    graph[wordList[to]].push_back(wordList[from]);
                }
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        bool has_found = false;
        for (auto const & word : wordList) {
            if (endWord == word) {
                has_found = true;
                break;
            }
        }
        if (!has_found) { return {}; }
        
        wordList.push_back(beginWord);
        wordList.push_back(endWord);
        build_graph(wordList);
        queue<string> q;
        q.push(beginWord);
        distance[beginWord] = 1;
        while(!q.empty()) {
            auto cur_word = q.front(); q.pop();
            for (auto neighbour : graph[cur_word]) {
                if (distance.count(neighbour)) { continue; }
                q.push(neighbour);
                distance[neighbour] = distance[cur_word] + 1;
            }
        }
        rec({endWord}, endWord);
        return {result_set.begin(), result_set.end()};
    }
private:
    unordered_map<string, vector<string> > graph;
    unordered_map<string, int> distance;
    set<vector<string> > result_set;
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

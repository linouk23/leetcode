// 609. Find Duplicate File in System - https://leetcode.com/problems/find-duplicate-file-in-system
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> map_result;
        vector<vector<string> > result;
        
        for (const auto & path : paths) {
            stringstream ss(path);
            string dir, nc;
            getline(ss, dir, ' ');
            while (getline(ss, nc, ' ')) {
                string fname = dir + '/' + nc.substr(0, nc.find('('));
                string fcontent = nc.substr(nc.find('(') + 1,
                                            nc.find(')') - nc.find('(') - 1);
                map_result[fcontent].push_back(fname);
            }
        }
        for (const auto &p : map_result) {
            if (p.second.size() == 1) { continue; }
            result.emplace_back(p.second);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

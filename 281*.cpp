// 281. Zigzag Iterator - https://leetcode.com/problems/zigzag-iterator

#include "bits/stdc++.h"

using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) {
            q.push({v1.begin(), v1.end()});
        }
        if (!v2.empty()) {
            q.push({v2.begin(), v2.end()});
        }
    }
    
    int next() {
        auto curIt = q.front().first;
        auto endIt = q.front().second;
        q.pop();
        if (curIt + 1 != endIt) {
            q.push({curIt + 1, endIt});
        }
        return *curIt;
    }
    
    bool hasNext() {
        return !q.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

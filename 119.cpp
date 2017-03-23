// 119. Pascal's Triangle II - https://leetcode.com/problems/pascals-triangle-ii

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> answer(rowIndex + 1);

        for (int i = 0; i < rowIndex + 1; i++) {
            answer[i].resize(i + 1);
            answer[i][0] = answer[i][i] = 1;
  
            for (int j = 1; j < i; j++)
                answer[i][j] = answer[i - 1][j - 1] + answer[i - 1][j];
        }
        
        return answer[rowIndex];
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

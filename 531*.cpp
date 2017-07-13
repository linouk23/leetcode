// 531. Lonely Pixel I - https://leetcode.com/problems/lonely-pixel-i

#include "bits/stdc++.h"

using namespace std;

// https://discuss.leetcode.com/topic/81679/java-c-clean-code-with-explanation
// A black lonely pixel is character 'B' that located at
// a specific position where the same row and same column
// don't have any other black pixels.
/**
 * suppose matrix is m*n, there is at most min(m, n) lonely pixels, because there could be no more than 1 in each row, or column;
 * therefore, if we record num of black pixel on each row and column, we can easily tell whether each pixel is lonely or NO.
 *     _0_1_2_
 *  0 | 0 0 1   rows[0] = 1
 *  1 | 0 1 0   rows[1] = 1
 *  2 | 1 0 0   rows[2] = 1
 *
 * cols[0][1][2]
 *     1  1  1
 */

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& pic) {
        int m = (int)pic.size();
        int n = (int)pic[0].size();
        auto rows = vector<int>(m, 0);
        auto cols = vector<int>(n, 0);
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (pic[row][col] != 'B') { continue; }
                rows[row] += 1;
                cols[col] += 1;
            }
        }
        int result = 0;
        for (int row = 0; row < m; ++row) {
            if (rows[row] == 0) { continue; }
            for (int col = 0; col < n; ++col) {
                bool isLonelyPixel = (pic[row][col] == 'B') &&
                                      (rows[row] == 1) &&
                                      (cols[col] == 1);
                result += isLonelyPixel ? 1 : 0;
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 157. Read N Characters Given Read4 - https://leetcode.com/problems/read-n-characters-given-read4

// Forward declaration of the read4 API.
int read4(char *buf);
// It assumes only read less than n chars,
// even if the there are more than n chars in a file.

class Solution {
public:
    int read(char *buf, int n) {
        int total = 0;
        // 10 = 4 * (10 / 4 == 2) + 2
        for (int i = 0; i < n / 4; i++)
            total += read4(buf + total);
        int remain = n - total;
        if (remain) {
            // 9 -> read = 1, remain = 2
            int read = read4(buf + total);
            return total + min(read, remain);
        }
        return n;
    }
};
// 346. Moving Average from Data Stream - https://leetcode.com/problems/moving-average-from-data-stream

#include "bits/stdc++.h"

using namespace std;

class MovingAverage {
private:
    queue<int> q;
    double sum;
    int avg_size;
public:
    MovingAverage(int size) : avg_size(size), sum(0) { }
    double next(int val) {
        sum += val;
        q.push(val);
        int q_len = (int)q.size();
        if (q_len <= avg_size){
            return sum / q_len;
        } else {
            sum -= q.front();
            q.pop();
            return sum / avg_size;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

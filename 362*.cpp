// 362. Design Hit Counter - https://leetcode.com/problems/design-hit-counter

#include "bits/stdc++.h"

using namespace std;

class HitCounter {
private:
    const int NUM_OF_SEC_IN_5_MIN = 60 * 5;
    // time - count
    queue<pair<int, int>> hits;
    int total_sum;
    void deleteOutdatedElems(int timestamp) {
        while(!hits.empty() && timestamp - hits.front().first >= NUM_OF_SEC_IN_5_MIN ){
            total_sum -= hits.front().second;
            hits.pop();
        }
    }
public:
    /** Initialize your data structure here. */
    HitCounter() : total_sum(0) { }
    
    /** Record a hit.
     @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        // maintain the queue to get rid of the outdated hit pair
        deleteOutdatedElems(timestamp);

        // Include current hit:
        ++total_sum;
        if(!hits.empty() && timestamp == hits.back().first) {
            // Increment counter.
            hits.back().second += 1;
        } else {
            hits.push({timestamp, 1});
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
     @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        deleteOutdatedElems(timestamp);
        return total_sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

// 635. Design Log Storage System - https://leetcode.com/problems/design-log-storage-system

#include "bits/stdc++.h"

using namespace std;

//put(1, "2017:01:01:23:59:59");
//put(2, "2017:01:01:22:59:59");
//put(3, "2016:01:01:00:00:00");
//retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"); // return [1,2,3], because you need to return all logs within 2016 and 2017.
//retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"); // return [1,2], because you need to return all logs start from 2016:01:01:01 to 2017:01:01:23, where log 3 is left outside the range.

class LogSystem {
private:
    struct Pair {
        int id;
        string timestamp;
    };
    vector<Pair> logs;
    unordered_map<string, int> map_idx;
public:
    LogSystem() {
        // For example, if the granularity is 'Day', we should truncate the
        // timestamp '2017:07:02:08:30:12' to be '2017:07:02'. Now for each
        // log, if the truncated timetuple cur is between start and end,
        // then we should add the id of that log into our answer.
        map_idx = {{"Year", 4},{"Month", 7}, {"Day", 10},
            {"Hour", 13}, {"Minute", 16}, {"Second", 19}};
    }
    
    void put(int id, string timestamp) {
        logs.push_back({id, timestamp});
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        auto is_within_range = [](const Pair &log,
                                  const string &start,
                                  const string &end, int len) -> bool {
            return log.timestamp.substr(0, len) >= start &&
                   log.timestamp.substr(0, len) <= end;
        };
        
        string start, end;
        int len = map_idx[gra];
        start = s.substr(0, len);
        end = e.substr(0, len);
        vector<int> result;
        // For example, if the granularity is 'Day', we should truncate the
        // timestamp '2017:07:02:08:30:12' to be '2017:07:02'. Now for each
        // log, if the truncated timetuple cur is between start and end,
        // then we should add the id of that log into our answer.
        for (const auto &log : logs) {
            if (is_within_range(log, start, end, len)) {
                result.emplace_back(log.id);
            }
        }
        return result;
    }
};



int main() {
    ios::sync_with_stdio(false);
    return 0;
}

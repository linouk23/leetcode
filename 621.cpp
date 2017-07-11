// 621. Task Scheduler - https://leetcode.com/problems/task-scheduler

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count_table;
        for (char task : tasks) {
            count_table[task] += 1;
        }
        int task, count;
        // Max heap
        priority_queue<pair<int, char>> pq;
        for (const auto &p : count_table) {
            tie(task, count) = p;
            pq.push({count, task});
        }
        int result = 0;
        while (!pq.empty()) {
            int len = n + 1;
            vector<char> used_tasks;
            while (len-- && !pq.empty()) {
                char task_name = pq.top().second;
                pq.pop();
                count_table[task_name] -= 1;
                used_tasks.emplace_back(task_name);
            }
            
            for (char task : used_tasks) {
                if (count_table[task] > 0) {
                    pq.push({count_table[task], task});
                }
            }
            result += pq.empty() ? (int)used_tasks.size() : n + 1;
        }
        return result;
    }
};

//  We don't really need to store <count, task> pair in the pq, we don't need to know the task name.

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

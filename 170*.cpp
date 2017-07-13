// 170. Two Sum III - Data structure design - https://leetcode.com/problems/two-sum-iii-data-structure-design

#include "bits/stdc++.h"

using namespace std;

//Design and implement a TwoSum class.
//It should support the following operations: add and find.
//
//add - Add the number to an internal data structure.
//find - Find if there exists any pair of numbers which
//sum is equal to the value.
//
//For example,
//add(1);
//add(3);
//add(5);
//find(4) -> true
//find(7) -> false

class TwoSum {
    // number - count
    unordered_map<int, int> countTable;
public:
    void add(int number) {
        countTable[number]++;
    }
    
    bool find(int value) {
        for (const auto &nc : countTable)
            if (countTable.count(value - nc.first) && (nc.first != value - nc.first || nc.second > 1))
                return true;
        return false;
    }
};

// class TwoSum {
//     unordered_multiset<int> nums;
// public:
//     void add(int number) {
//         nums.insert(number);
//     }
//     bool find(int value) {
//         for (int i : nums) {
//             int count = i == value - i ? 1 : 0;
//             if (nums.count(value - i) > count) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

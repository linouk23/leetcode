// 122. Best Time to Buy and Sell Stock II - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        for (int index = 1; index < (int)prices.size(); ++index) {
            answer += max(0, prices[index] - prices[index - 1]);
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

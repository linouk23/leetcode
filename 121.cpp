// 121. Best Time to Buy and Sell Stock - https://leetcode.com/problems/best-time-to-buy-and-sell-stock

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        Result result;
        for (int price : prices) {
            result.updateMinPrice(price);
            result.tryToSell(price);
        }
        return result.maxProfitSoFar;
    }
private:
    struct Result {
        int maxProfitSoFar, minPriceSoFar;
        Result(): maxProfitSoFar(0), minPriceSoFar(INT_MAX) {};
        
        void updateMinPrice(int currentPrice) {
            minPriceSoFar = min(minPriceSoFar, currentPrice);
        }
        
        void tryToSell(int currentPrice) {
            maxProfitSoFar = max(maxProfitSoFar, currentPrice - minPriceSoFar);
        }
    };
};

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

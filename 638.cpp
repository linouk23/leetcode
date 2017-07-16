// 638. Shopping Offers - https://leetcode.com/problems/shopping-offers/

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class Solution {
private:
    const int INF = (int)1e9;
    int n;
    unordered_map<string, int> memo;
    inline string v_to_str(const vector<int> &nums) {
        string result = "";
        for (const int &num : nums) {
            result += ('0' + num);
        }
        return result;
    }
    inline bool is_negative(const vector<int> &nums) {
        for (const int &num : nums) {
            if (num < 0) { return true; }
        }
        return false;
    }
    
    inline bool is_zero(const vector<int> &nums) {
        for (const int &num : nums) {
            if (num != 0) { return false; }
        }
        return true;
    }
    
    inline void apply_offer(vector<int> &needs, vector<int> offer) {
        for (int idx = 0; idx < n; ++idx) {
            needs[idx] -= offer[idx];
        }
    }
    
    inline void cancel_offer(vector<int> &needs, vector<int> offer) {
        for (int idx = 0; idx < n; ++idx) {
            needs[idx] += offer[idx];
        }
    }
    
    int run_knapsack(vector<int> needs,
                     vector<int> &price,
                     vector<vector<int>> &special) {
        if (is_negative(needs)) { return INF; }
        auto key = v_to_str(needs);
        if (memo.count(key)) { return memo[key]; }
        int result = INF;
        
        for (int idx = 0; idx < (int)special.size(); ++idx) {
            apply_offer(needs, special[idx]);
            result = min(result, run_knapsack(needs, price, special)
                         + special[idx].back());
            cancel_offer(needs, special[idx]);
        }
        
        int sum_without_offers = 0;
        for (int idx = 0; idx < n; ++idx) {
            sum_without_offers += needs[idx] * price[idx];
        }
        result = min(result, sum_without_offers);
//        for (int idx = 0; idx < n; ++idx) {
//            needs[idx] -= 1;
//            result = min(result, run_knapsack(needs, price, special)
//                                 + price[idx]);
//            needs[idx] += 1;
//        }
        
        memo[key] = result;
        return memo[key];
    }
public:
    int shoppingOffers(vector<int> price, vector<vector<int>> special, vector<int> needs) {
        n = (int)price.size();
        memo[string(n, '0')] = 0;
        return run_knapsack(needs, price, special);
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ(14, sol.shoppingOffers({2,5}, {{3,0,5},{1,2,10}}, {3,2}));
    EXPECT_EQ(11, sol.shoppingOffers({2,3,4}, {{1,1,0,4},{2,2,1,9}}, {1,2,1}));
}


int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

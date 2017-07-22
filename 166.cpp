// 166. Fraction to Recurring Decimal - https://leetcode.com/problems/fraction-to-recurring-decimal

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

typedef long long ll;

class Solution {
public:
    // upgraded parameter types
    string fractionToDecimal(ll n, ll d) {
        if (n == 0) return "0";
        string result;
        if (n < 0 ^ d < 0) result += '-';
        n = abs(n), d = abs(d);
        result += to_string(n / d);
        if (n % d == 0) return result;
        result += '.';
        
        // rem -> idx
        unordered_map<ll, ll> map;
        
        // Simulate the division process:
        for (ll r = n % d; r; r %= d) {
            if (map.count(r) > 0) {
                result.insert(map[r], 1, '(');
                result += ')';
                break;
            }
            map[r] = result.size();
            r *= 10;
            result += to_string(r / d);
        }
        return result;
    }
};

TEST(SolutionTest, Small) {
    Solution sol;
    EXPECT_EQ("0.5", sol.fractionToDecimal(1, 2));
    EXPECT_EQ("2", sol.fractionToDecimal(2, 1));
    EXPECT_EQ("0.(6)", sol.fractionToDecimal(2, 3));
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

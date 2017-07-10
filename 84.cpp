// 84. Largest Rectangle in Histogram - https://leetcode.com/problems/largest-rectangle-in-histogram

#include "bits/stdc++.h"

using namespace std;

// Any time you reach a new height in the histogram
// going from L to R, you could be starting a new Rectangle.
class Solution {
private:
    struct Rec {
        int start, height;
    };
    // Invariant: there's an increasing seq in the stack.
    stack<Rec> st;
    int result = 0;
    int eval_and_get_prev_start(int finish, int height) {
        int prev_start = 0;
        while (!st.empty() && st.top().height > height) {
            prev_start = st.top().start;
            // area = width * height
            int tmp_result = (finish - st.top().start) * st.top().height;
            result = max(result, tmp_result);
            st.pop();
        }
        return prev_start;
    }
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = (int)heights.size();
        for (int idx = 0; idx < n; ++idx) {
            int height = heights[idx];
            // Start new rectangle:
            if (st.empty() || st.top().height < height) {
                st.push({idx, height});
            
            // Our top rectangle is done! -> [3, 1]:
            // +
            // +
            // + +
            } else if (st.top().height > height) {
                // Invariant: there's an increasing seq in the stack.
                // Popping until we can insert new start height
                // [3, 4, 10, 15] and 5 => [3, 4, 5*]  -> push, update start
                // 5*.start == 10.start => start = last deleted start (we can
                // start from there, cause deleted.height > our.height
                // [3, 4, 10, 15] and 4 => [3, 4] -> don't push, don't upd start
                // kinda skip equal blocks => pop 2 times.
                int prev_start = eval_and_get_prev_start(idx, height);
                
                // so far:
                // [3, 4, 10, 15] and 4 => [3, 4] (+)
                // [3, 4, 10, 15] and 5 => [3, 4] (-, should be [3, 4, 5])
                // [2] and 1            => []     (-, should be [1])
                st.push({prev_start, height});
                // [3, 4, 10, 15] and 4 => [3, 4]    (+)
                // [3, 4, 10, 15] and 5 => [3, 4, 5*] (+), 5* = [2, 5]
                // [2] and 1            => [1*]       (+), 1* = [0, 1]
                //                                           start, height
            }
        }
        int finish_of_rec = n;
        // height = INT_MIN -> so we'll be able to clear the whole stack while
        // going down (finish every rectangle),
        // condition is while st.top().height > height.
        std::ignore = eval_and_get_prev_start(finish_of_rec, INT_MIN);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}

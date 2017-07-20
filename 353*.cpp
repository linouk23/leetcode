// 353. Design Snake Game - https://leetcode.com/problems/design-snake-game

#include "bits/stdc++.h"
#include "gtest/gtest.h"

using namespace std;

class SnakeGame {
public:
    /** Initialize your data structure here.
     @param width - screen width
     @param height - screen height
     @param food - A list of food food_idxitions
     E.g food = [[1,1], [1,0]] means the first food is food_idxitioned at [1,1], the second is at [1,0]. */
    
    int w, h, food_idx;
    vector<pair<int, int>> food;
    set<pair<int, int>> set_of_pixels;
    deque<pair<int, int>> deq_of_pixels;
    
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->food = food;
        w = width, h = height, food_idx = 0;
        deq_of_pixels.push_back({0, 0});
    }
    
    /** Moves the snake.
     @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
     @return The game's score after the move. Return -1 if game over.
     Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int row = deq_of_pixels.back().first, col = deq_of_pixels.back().second;
        pair<int, int> last_pixel = deq_of_pixels.front();
        deq_of_pixels.pop_front();
        set_of_pixels.erase(last_pixel);
        
        if (direction == "U") { row -= 1; }
        else if (direction == "D") { row += 1; }
        else if (direction == "L") { col -= 1; }
        else if (direction == "R") { col += 1; }
        
        if (row < 0 || col < 0 || col >= w || row >= h ||
            set_of_pixels.count({row, col})) {
            return -1;
        }
        
        set_of_pixels.insert({row, col});
        deq_of_pixels.push_back({row, col});
        
        if (food_idx >= food.size()) { return (int)deq_of_pixels.size() - 1; }
        
        if (row == food[food_idx].first && col == food[food_idx].second) {
            food_idx += 1;
            deq_of_pixels.push_front(last_pixel);
            set_of_pixels.insert(last_pixel);
        }
        
        return (int)deq_of_pixels.size() - 1;
    }
};

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

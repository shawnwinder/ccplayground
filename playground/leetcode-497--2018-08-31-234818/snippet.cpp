// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

/*
 * [914] Random Point in Non-overlapping Rectangles
 *
 * https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/
 *
 * algorithms
 * Medium (33.81%)
 * Total Accepted:    1.1K
 * Total Submissions: 3.3K
 * Testcase Example:  '["Solution", "pick", "pick", "pick"]\n[[[[1, 1, 5, 5]]], [], [], []]'
 *
 * Given a list of non-overlapping axis-aligned rectangles rects, write a
 * function pick which randomly and uniformily picks an integer point in the
 * space covered by the rectangles.
 *
 * Note:
 *
 *
 * An integer point is a point that has integer coordinates.
 * A point on the perimeter of a rectangle is included in the space covered by
 * the rectangles.
 * ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer
 * coordinates of the bottom-left corner, and [x2, y2] are the integer
 * coordinates of the top-right corner.
 * length and width of each rectangle does not exceed 2000.
 * 1 <= rects.length <= 100
 * pick return a point as an array of integer coordinates [p_x, p_y]
 * pick is called at most 10000 times.
 *
 *
 *
 * Example 1:
 *
 *
 * Input:
 * ["Solution","pick","pick","pick"]
 * [[[[1,1,5,5]]],[],[],[]]
 * Output:
 * [null,[4,1],[4,1],[3,3]]
 *
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ["Solution","pick","pick","pick","pick","pick"]
 * [[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
 * Output:
 * [null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
 *
 *
 *
 * Explanation of Input Syntax:
 *
 * The input is two lists: the subroutines called and their arguments.
 * Solution's constructor has one argument, the array of rectangles rects. pick
 * has no arguments. Arguments are always wrapped with a list, even if there
 * aren't any.
 *
 *
 *
 *
 *
 *
 *
 */
class Solution {
    vector<int> v;
    vector<vector<int>> rects;
    random_device r;
    default_random_engine e1;
    uniform_int_distribution<int> uniform_dist;

    int area(vector<int>& r) { return (r[2] - r[0] + 1) * (r[3] - r[1] + 1); }

public:
    Solution(vector<vector<int>> rects_)
        : rects(std::move(rects_))
        , e1(r()) {
        v.push_back(0);
        for (auto& r : rects) {
            v.push_back(area(r) + (v.empty() ? 0 : v.back()));
        }
        uniform_dist = uniform_int_distribution<int>(0, v.back() - 1);
    }

    vector<int> pick() {
        int rnd = uniform_dist(e1);
        auto it = prev(upper_bound(v.begin(), v.end(), rnd));
        auto a = rnd - *it;
        int idx = it - v.begin();
        auto& r = rects[idx];
        return { a / (r[3] - r[1] + 1) + r[0], a % (r[3] - r[1] + 1) + r[1] };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */

int mymain(int argc, char* argv[]) {
    Solution obj({ { 1, 1, 5, 5 } });
    obj.pick();
    obj.pick();
    obj.pick();
    return 0;
}

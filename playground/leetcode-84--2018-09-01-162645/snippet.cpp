// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (28.48%)
 * Total Accepted:    131.5K
 * Total Submissions: 461.7K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 *
 *
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 *
 *
 *
 *
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 *
 *
 *
 * Example:
 *
 *
 * Input: [2,1,5,6,2,3]
 * Output: 10
 *
 *
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int ret = 0;
        height.push_back(0);
        vector<int> index;
        for (int i = 0; i < height.size(); i++) {
            while (index.size() && height[index.back()] >= height[i]) {
                int h = height[index.back()];
                index.pop_back();
                int l = index.size() ? index.back() : -1;
                if (h * (i - l - 1) > ret)
                    ret = h * (i - l - 1);
            }
            index.push_back(i);
        }
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }

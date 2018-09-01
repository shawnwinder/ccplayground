// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (38.89%)
 * Total Accepted:    192.8K
 * Total Submissions: 495.9K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 *
 * Example:
 *
 *
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 */
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2)
            return 0;
        int lm = height[0];
        int rm = height.back();
        int l = 1;
        int r = height.size() - 2;
        int ret = 0;
        while (l <= r) {
            if (lm < rm) {
                if (height[l] > lm)
                    lm = height[l];
                else
                    ret += lm - height[l];
                l++;
            } else {
                if (height[r] > rm)
                    rm = height[r];
                else
                    ret += rm - height[r];
                r--;
            }
        }
        return ret;
    }
};

int mymain(int argc, char* argv[]) { return 0; }

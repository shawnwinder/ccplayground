// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (30.59%)
 * Total Accepted:    94.8K
 * Total Submissions: 310K
 * Testcase Example:
 * '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 *
 * Example:
 *
 *
 * Input:
 * [
 *  ["1","0","1","0","0"],
 *  ["1","0","1","1","1"],
 *  ["1","1","1","1","1"],
 *  ["1","0","0","1","0"]
 * ]
 * Output: 6
 *
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int maxRec = 0;
        vector<int> height(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0') {
                    height[j] = 0;
                } else {
                    height[j]++;
                }
            }
            maxRec = max(maxRec, largestRectangleArea(height));
        }
        return maxRec;
    }

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

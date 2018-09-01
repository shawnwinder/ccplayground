// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

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
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 *
 * Example:
 *
 *
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 *
 *
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (m < n) {
            vector<vector<char>> mm(n, vector<char>(m));
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    mm[j][i] = matrix[i][j];
                }
            }
            matrix = mm;
            swap(m, n);
        }
        vector<int> histo(n);
        int ret = 0;
        for (int i=0;i<m;i++) {
            stack<int> s;
            int tp;  // To store top of stack
            int area_with_top; // To store area with top bar as the smallest bar
            for (int j=0;j<n;j++) {
                histo[j] = matrix[i][j] == '0' ? 0 : histo[j] + 1;
            }
            // Run through all bars of given histogram
            int j = 0;
            while (j < n)
            {
                // If this bar is higher than the bar on top stack, push it to stack
                if (s.empty() || histo[s.top()] <= histo[j])
                    s.push(j++);

                // If this bar is lower than top of stack, then calculate area of rectangle 
                // with stack top as the smallest (or minimum height) bar. 'i' is 
                // 'right index' for the top and element before top in stack is 'left index'
                else
                {
                    tp = s.top();  // store the top index
                    s.pop();  // pop the top

                    // Calculate the area with hist[tp] stack as smallest bar
                    area_with_top = histo[tp] * (s.empty() ? j : j - s.top() - 1);

                    // update max area, if needed
                    if (ret < area_with_top)
                        ret = area_with_top;
                }
            }

            // Now pop the remaining bars from stack and calculate area with every
            // popped bar as the smallest bar
            while (s.empty() == false)
            {
                tp = s.top();
                s.pop();
                area_with_top = histo[tp] * (s.empty() ? j : j - s.top() - 1);

                if (ret < area_with_top)
                    ret = area_with_top;
            }
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}

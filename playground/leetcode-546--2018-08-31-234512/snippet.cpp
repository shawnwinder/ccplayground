// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [546] Remove Boxes
 *
 * https://leetcode.com/problems/remove-boxes/description/
 *
 * algorithms
 * Hard (36.75%)
 * Total Accepted:    7.1K
 * Total Submissions: 19.3K
 * Testcase Example:  '[1,3,2,2,2,3,4,3,1]'
 *
 * Given several boxes with different colors represented by different positive
 * numbers.
 * You may experience several rounds to remove boxes until there is no box
 * left. Each time you can choose some continuous boxes with the same color
 * (composed of k boxes, k >= 1), remove them and get k*k points.
 * Find the maximum points you can get.
 *
 *
 * Example 1:
 * Input:
 *
 * [1, 3, 2, 2, 2, 3, 4, 3, 1]
 *
 * Output:
 *
 * 23
 *
 * Explanation:
 *
 * [1, 3, 2, 2, 2, 3, 4, 3, 1]
 * ----> [1, 3, 3, 4, 3, 1] (3*3=9 points)
 * ----> [1, 3, 3, 3, 1] (1*1=1 points)
 * ----> [1, 1] (3*3=9 points)
 * ----> [] (2*2=4 points)
 *
 *
 *
 * Note:
 * The number of boxes n would not exceed 100.
 *
 *
 */
class Solution {
    int memo[100][100][100] = { 0 };

    int dfs(vector<int>& boxes, int l, int r, int k) {
        if (l > r)
            return 0;
        if (memo[l][r][k] != 0)
            return memo[l][r][k];
        while (r > l && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }
        memo[l][r][k] = dfs(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                memo[l][r][k]
                    = max(memo[l][r][k], dfs(boxes, l, i, k + 1) + dfs(boxes, i + 1, r - 1, 0));
            }
        }
        return memo[l][r][k];
    }

public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        return dfs(boxes, 0, n - 1, 0);
    }
};

int mymain(int argc, char* argv[]) { return 0; }

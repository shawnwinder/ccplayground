// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (31.04%)
 * Total Accepted:    98.7K
 * Total Submissions: 318K
 * Testcase Example:
 * '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 *
 * Example:
 *
 *
 * Input:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Output: 4
 *
 *
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& a) {
        if (a.empty())
            return 0;
        int m = a.size(), n = a[0].size(), ans = 0;
        vector<int> s(n, 0);
        for (int i = 0; i < m; i++) {
            int ul = 0;
            for (int j = 0; j < n; j++) {
                int t = ul;
                ul = s[j];
                s[j] = a[i][j] == '1' ? min(min(t, s[j - 1]), s[j]) + 1 : 0;
                ans = max(ans, s[j]);
            }
        }
        return ans * ans;
    }
};

int mymain(int argc, char* argv[]) { return 0; }

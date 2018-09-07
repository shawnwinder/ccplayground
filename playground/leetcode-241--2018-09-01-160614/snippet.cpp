// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (47.15%)
 * Total Accepted:    .5K
 * Total Submissions: 128.4K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 *
 * Example 1:
 *
 *
 * Input: "2-1-1"
 * Output: [0, 2]
 * Explanation:
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 *
 * Example 2:
 *
 *
 * Input: "2*3-4*5"
 * Output: [-34, -14, -10, -10, 10]
 * Explanation:
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 *
 *
 */
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        stringstream ss;
        ss << input;
        vector<int> vals;
        vector<char> ops;
        int v;
        char op;
        ss >> v;
        vals.push_back(v);
        while (ss >> op) {
            ops.push_back(op);
            ss >> v;
            vals.push_back(v);
        }
        int n = vals.size();
        auto dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i].push_back(vals[i]);
        }
        for (int k = 1; k < n; k++) {
            for (int i = 0, j = i + k; j < n; i++, j++) {
                for (int l = i; l < j; l++) {
                    for (auto a : dp[i][l])
                        for (auto b : dp[l + 1][j]) {
                            int val;
                            switch (ops[l]) {
                            case '+':
                                val = a + b;
                                break;
                            case '-':
                                val = a - b;
                                break;
                            case '*':
                                val = a * b;
                                break;
                            }
                            dp[i][j].push_back(val);
                        }
                }
            }
        }
        return dp[0][n - 1];
    }
};

int mymain(int argc, char* argv[]) { return 0; }

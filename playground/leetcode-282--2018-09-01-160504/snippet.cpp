// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [282] Expression Add Operators
 *
 * https://leetcode.com/problems/expression-add-operators/description/
 *
 * algorithms
 * Hard (30.96%)
 * Total Accepted:    52.3K
 * Total Submissions: 168.9K
 * Testcase Example:  '"123"\n6'
 *
 * Given a string that contains only digits 0-9 and a target value, return all
 * possibilities to add binary operators (not unary) +, -, or * between the
 * digits so they evaluate to the target value.
 *
 * Example 1:
 *
 *
 * Input: num = "123", target = 6
 * Output: ["1+2+3", "1*2*3"]
 *
 *
 * Example 2:
 *
 *
 * Input: num = "232", target = 8
 * Output: ["2*3+2", "2+3*2"]
 *
 * Example 3:
 *
 *
 * Input: num = "105", target = 5
 * Output: ["1*0+5","10-5"]
 *
 * Example 4:
 *
 *
 * Input: num = "00", target = 0
 * Output: ["0+0", "0-0", "0*0"]
 *
 *
 * Example 5:
 *
 *
 * Input: num = "3456237490", target = 9191
 * Output: []
 *
 *
 */
class Solution {
    vector<string> res;
    string num;
    int target;
    void dfs(int pos, string cur, long add, long mul, long last) {
        long sum = add + mul * last;
        if (pos == num.size()) {
            if (sum == target)
                res.push_back(cur);
            return;
        }
        int x = num[pos] - '0';
        dfs(pos + 1, cur + '*' + num[pos], add, mul * last, x);
        dfs(pos + 1, cur + '+' + num[pos], sum, 1, x);
        dfs(pos + 1, cur + '-' + num[pos], sum, -1, x);
        // no op
        if (last)
            dfs(pos + 1, cur + num[pos], add, mul, last * 10 + x);
    }

public:
    vector<string> addOperators(string num, int target) {
        if (num.empty())
            return res;
        this->num = num;
        this->target = target;
        dfs(1, num.substr(0, 1), 0, 1, num[0] - '0');
        return res;
    }
};

int mymain(int argc, char* argv[]) { return 0; }

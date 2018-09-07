// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [553] Optimal Division
 *
 * https://leetcode.com/problems/optimal-division/description/
 *
 * algorithms
 * Medium (55.14%)
 * Total Accepted:    16.5K
 * Total Submissions: 30K
 * Testcase Example:  '[1000,100,10,2]'
 *
 * Given a list of positive integers, the adjacent integers will perform the
 * float division. For example, [2,3,4] -> 2 / 3 / 4.
 *
 * However, you can add any number of parenthesis at any position to change the
 * priority of operations. You should find out how to add parenthesis to get
 * the maximum result, and return the corresponding expression in string
 * format. Your expression should NOT contain redundant parenthesis.
 *
 * Example:
 *
 * Input: [1000,100,10,2]
 * Output: "1000/(100/10/2)"
 * Explanation:
 * 1000/(100/10/2) = 1000/((100/10)/2) = 200
 * However, the bold parenthesis in "1000/((100/10)/2)" are redundant, since
 * they don't influence the operation priority. So you should return
 * "1000/(100/10/2)".
 *
 * Other cases:
 * 1000/(100/10)/2 = 50
 * 1000/(100/(10/2)) = 50
 * 1000/100/10/2 = 0.5
 * 1000/100/(10/2) = 2
 *
 *
 *
 * Note:
 *
 * The length of the input array is [1, 10].
 * Elements in the given array will be in range [2, 1000].
 * There is only one optimal division for each test case.
 *
 *
 */
class Solution {
public:
    string optimalDivision(vector<int>& a) {
        if (a.size() == 1)
            return to_string(a[0]);
        if (a.size() == 2)
            return to_string(a[0]) + '/' + to_string(a[1]);
        string r = to_string(a[0]) + "/(";
        for (auto i = 1; i < a.size(); ++i) {
            if (i > 1)
                r += '/';
            r += to_string(a[i]);
        };
        return r + ')';
    }
};

int mymain(int argc, char* argv[]) { return 0; }

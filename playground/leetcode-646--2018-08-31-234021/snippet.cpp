// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [646] Maximum Length of Pair Chain
 *
 * https://leetcode.com/problems/maximum-length-of-pair-chain/description/
 *
 * algorithms
 * Medium (47.51%)
 * Total Accepted:    25K
 * Total Submissions: 52.7K
 * Testcase Example:  '[[1,2], [2,3], [3,4]]'
 *
 *
 * You are given n pairs of numbers. In every pair, the first number is always
 * smaller than the second number.
 *
 *
 *
 * Now, we define a pair (c, d) can follow another pair (a, b) if and only if b
 * < c. Chain of pairs can be formed in this fashion.
 *
 *
 *
 * Given a set of pairs, find the length longest chain which can be formed. You
 * needn't use up all the given pairs. You can select pairs in any order.
 *
 *
 *
 * Example 1:
 *
 * Input: [[1,2], [2,3], [3,4]]
 * Output: 2
 * Explanation: The longest chain is [1,2] -> [3,4]
 *
 *
 *
 * Note:
 *
 * The number of given pairs will be in the range [1, 1000].
 *
 *
 */
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int l = pairs[0][1];
        int ret = 1;
        for (int i=1;i<pairs.size();i++) {
            if (pairs[i][0]>l) {
                l = pairs[i][1];
                ret ++;
            }
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}

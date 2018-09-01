// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [421] Maximum XOR of Two Numbers in an Array
 *
 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
 *
 * algorithms
 * Medium (48.94%)
 * Total Accepted:    27.1K
 * Total Submissions: 55.3K
 * Testcase Example:  '[3,10,5,25,2,8]'
 *
 * Given a non-empty array of numbers, a0, a1, a2, ... , an-1, where 0 <= ai <
 * 231.
 *
 * Find the maximum result of ai XOR aj, where 0 <= i, j < n.
 *
 * Could you do this in O(n) runtime?
 *
 * Example:
 *
 * Input: [3, 10, 5, 25, 2, 8]
 *
 * Output: 28
 *
 * Explanation: The maximum result is 5 ^ 25 = 28.
 *
 *
 */
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        for (int i=1<<30; i>0; i>>=1) {
            unordered_set<int> s;
            int nans = ans|i;
            int fmask = ~(i-1);
            for (int n : nums) {
                if (s.count(n&fmask)) {
                    ans = nans;
                    break;
                } else {
                    s.insert(nans ^ (n&fmask));
                }
            }
        }
        return ans;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}

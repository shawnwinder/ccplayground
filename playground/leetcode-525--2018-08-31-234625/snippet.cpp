// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [525] Contiguous Array
 *
 * https://leetcode.com/problems/contiguous-array/description/
 *
 * algorithms
 * Medium (41.95%)
 * Total Accepted:    29.8K
 * Total Submissions: 71.1K
 * Testcase Example:  '[0,1]'
 *
 * Given a binary array, find the maximum length of a contiguous subarray with
 * equal number of 0 and 1.
 *
 *
 * Example 1:
 *
 * Input: [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with equal number of
 * 0 and 1.
 *
 *
 *
 * Example 2:
 *
 * Input: [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal
 * number of 0 and 1.
 *
 *
 *
 * Note:
 * The length of the given binary array will not exceed 50,000.
 *
 */
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_map<int, int> m;
        m[0] = -1;
        int acc = 0;
        int ret = 0;
        for (int i=0;i<nums.size();i++) {
            acc += nums[i] == 0? -1 : 1;
            if (m.find(acc) == m.end()) {
                m[acc] = i;
            } else {
                ret = max(ret, i - m[acc]);
            }
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}

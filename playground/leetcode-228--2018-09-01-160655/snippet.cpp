// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (33.36%)
 * Total Accepted:    108.2K
 * Total Submissions: 324.3K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 *
 * Example 1:
 *
 *
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 *
 *
 * Example 2:
 *
 *
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 *
 *
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        nums.push_back(INT_MAX);
        int s = nums[0], t = nums[0];
        vector<string> ret;
        for (int i=1;i<nums.size();i++) {
            if (i == nums.size() || nums[i] > nums[i-1] + 1) {
                ret.push_back(s == t? to_string(s) : to_string(s)+ "->" + to_string(t));
                s = t = nums[i];
            } else {
                t = nums[i];
            }
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}

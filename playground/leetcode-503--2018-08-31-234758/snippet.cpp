// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (48.36%)
 * Total Accepted:    32.9K
 * Total Submissions: 68.1K
 * Testcase Example:  '[1,2,1]'
 *
 *
 * Given a circular array (the next element of the last element is the first
 * element of the array), print the Next Greater Number for every element. The
 * Next Greater Number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, output -1 for this
 * number.
 *
 *
 * Example 1:
 *
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; The number 2 can't find
 * next greater number; The second 1's next greater number needs to search
 * circularly, which is also 2.
 *
 *
 *
 * Note:
 * The length of given array won't exceed 10000.
 *
 */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ret(nums.size(), -1);
        deque<vector<int>> s;
        for (int i=0; i<nums.size(); i++) {
              while (!s.empty() && s.back()[1] < nums[i]) {
                  ret[s.back()[0]] = nums[i];
                  s.pop_back();
              }
            s.push_back({i, nums[i]});
        }
        
        for (int i=0; i<nums.size(); i++) {
            while (!s.empty() && s.back()[1] < nums[i]) {
                ret[s.back()[0]] = nums[i];
                s.pop_back();
            }
            if (s.empty()) break;
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}

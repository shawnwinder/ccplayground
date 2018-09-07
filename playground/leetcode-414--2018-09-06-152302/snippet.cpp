// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

/*
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (28.20%)
 * Total Accepted:    69.3K
 * Total Submissions: 245.7K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 *
 * Example 1:
 *
 * Input: [3, 2, 1]
 *
 * Output: 1
 *
 * Explanation: The third maximum is 1.
 *
 *
 *
 * Example 2:
 *
 * Input: [1, 2]
 *
 * Output: 2
 *
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 *
 *
 *
 * Example 3:
 *
 * Input: [2, 2, 3, 1]
 *
 * Output: 1
 *
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 *
 *
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long a, b, c;
        a = b = c = LONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == a || nums[i] == b || nums[i] == c)
                continue;
            if (nums[i] > a) {
                c = b;
                b = a;
                a = nums[i];
            } else if (nums[i] > b) {
                c = b;
                b = nums[i];
            } else if (nums[i] > c) {
                c = nums[i];
            }
        }
        if (c == LONG_MIN)
            return a;
        else
            return c;
    }
};

int mymain(int argc, char* argv[]) { return 0; }

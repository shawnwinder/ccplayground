// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>

using namespace std;

/*
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (52.24%)
 * Total Accepted:    334K
 * Total Submissions: 639.2K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 *
 * Example:
 *
 *
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 *
 * Note:
 *
 *
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 *
 *
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int offset = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                offset++;
            else
                nums[i - offset] = nums[i];
        }
        for (int i = nums.size() - offset; i < nums.size(); i++)
            nums[i] = 0;
    }
};

int mymain(int argc, char* argv[]) { return 0; }

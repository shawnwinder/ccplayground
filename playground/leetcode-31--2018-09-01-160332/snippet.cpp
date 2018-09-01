// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (29.21%)
 * Total Accepted:    170.3K
 * Total Submissions: 582.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty())
            return;
        int i = nums.size() - 2;
        for (; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                break;
        }
        reverse(nums.begin() + i + 1, nums.end());
        if (i == -1)
            return;
        swap(nums[i], *upper_bound(nums.begin() + i + 1, nums.end(), nums[i]));
    }
};

int mymain(int argc, char* argv[]) { return 0; }

// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (54.31%)
 * Total Accepted:    88.8K
 * Total Submissions: 163.4K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 *
 * Example:
 *
 *
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 *
 * Note:
 *
 *
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 *
 *
 */
class Solution {
public:
    // int get(vector<int>& nums, int i, int j) {
    //     int ret = 0;
    //     for (int k = i; k <= j; k++) {
    //         ret ^= nums[k];
    //     }
    //     return ret;
    // }

    // vector<int> singleNumber(vector<int>& nums) {
    //     int zeros = 0;
    //     for (auto i = nums.begin(); i != nums.end();) {
    //         if (*i == 0) {
    //             zeros++;
    //             nums.erase(i);
    //         } else {
    //             i++;
    //         }
    //     }
    //     if (zeros == 1) {
    //         int ans = 0;
    //         for (int i : nums) {
    //             ans ^= i;
    //         }
    //         return { ans, 0 };
    //     } else {
    //         int l = 0;
    //         int r = nums.size() - 1;
    //         while (true) {
    //             if (l >= r)
    //                 break;
    //             int pivot = nums[l];
    //             int i = l;
    //             int j = r;
    //             while (i < j) {
    //                 while (j > i && nums[j] > pivot)
    //                     j--;
    //                 if (i < j)
    //                     nums[i] = nums[j];
    //                 while (i < j && nums[i] <= pivot)
    //                     i++;
    //                 if (i < j)
    //                     nums[j] = nums[i];
    //             }
    //             nums[i] = pivot;
    //             int x = get(nums, l, i);
    //             int y = get(nums, i + 1, r);
    //             if (x != 0 && y != 0)
    //                 return { x, y };
    //             if (x != 0)
    //                 r = i;
    //             if (y != 0)
    //                 l = i + 1;
    //         }
    //     }
    //     return {-1, -1};
    // }
    vector<int> singleNumber(vector<int>& nums) {
        // Pass 1 :
        // Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Get its last set bit
        diff &= -diff;

        // Pass 2 :
        vector<int> rets = { 0, 0 }; // this vector stores the two numbers we will return
        for (int num : nums) {
            if ((num & diff) == 0) // the bit is not set
            {
                rets[0] ^= num;
            } else // the bit is set
            {
                rets[1] ^= num;
            }
        }
        return rets;
    }
};

int mymain(int argc, char* argv[]) { return 0; }

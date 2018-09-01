// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (49.31%)
 * Total Accepted:    291.3K
 * Total Submissions: 590.8K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,2,3]
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0;
        int m = 0;
        for (int i:nums) {
            if (c == 0) {
                m = i;
                c ++;
            } else if (i == m) {
                c ++;
            } else c --;
        }
        return m;
    }
};



int mymain(int argc, char *argv[]) {
    return 0;
}

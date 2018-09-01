// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (39.74%)
 * Total Accepted:    33.4K
 * Total Submissions: 84.1K
 * Testcase Example:  '[1,2,2,4]'
 *
 *
 * The set S originally contains numbers from 1 to n. But unfortunately, due to
 * the data error, one of the numbers in the set got duplicated to another
 * number in the set, which results in repetition of one number and loss of
 * another number.
 *
 *
 *
 * Given an array nums representing the data status of this set after the
 * error. Your task is to firstly find the number occurs twice and then find
 * the number that is missing. Return them in the form of an array.
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 *
 *
 *
 * Note:
 *
 * The given array size will in the range [2, 10000].
 * The given array's numbers won't have any order.
 *
 *
 */
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int x = 0;
        for (int n: nums) x ^= n;
        for (int i=1;i<=nums.size();i++) x ^= i;
        int bit = x & (-x);
        int x1 = 0, x2 = 0;
        for (int i=1; i<=nums.size(); i++) {
            if (bit & i) x1 ^= i; else x2 ^= i;
            if (bit & nums[i-1]) x1 ^= nums[i-1]; else x2 ^= nums[i-1];
        }
        for (int n:nums) {
            if (x1 == n) return {x1, x2};
        }
        return {x2, x1};
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}

// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [611] Valid Triangle Number
 *
 * https://leetcode.com/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (42.41%)
 * Total Accepted:    22.6K
 * Total Submissions: 53.3K
 * Testcase Example:  '[2,2,3,4]'
 *
 * Given an array consists of non-negative integers,  your task is to count the
 * number of triplets chosen from the array that can make triangles if we take
 * them as side lengths of a triangle.
 *
 * Example 1:
 *
 * Input: [2,2,3,4]
 * Output: 3
 * Explanation:
 * Valid combinations are:
 * 2,3,4 (using the first 2)
 * 2,3,4 (using the second 2)
 * 2,2,3
 *
 *
 *
 * Note:
 *
 * The length of the given array won't exceed 1000.
 * The integers in the given array are in the range of [0, 1000].
 *
 *
 *
 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ret = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i=0; i<(int)nums.size() - 2;i ++) {
            int k = distance(nums.begin(), --lower_bound(nums.begin() + i, nums.end(), nums[i] - nums[i+1], greater<int>()));
            for (int j=i+1; j<k;j++) {
                while (k > j && nums[j] + nums[k] <= nums[i]) k --;
                ret += k - j;
            }
        }
        return ret;
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}

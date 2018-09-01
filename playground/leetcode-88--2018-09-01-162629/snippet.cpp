// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (33.10%)
 * Total Accepted:    266.1K
 * Total Submissions: 803.9K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 *
 * Note:
 *
 *
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 *
 *
 * Example:
 *
 *
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 *
 * Output: [1,2,2,3,5,6]
 *
 *
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r = m + n - 1;
        int a = m - 1;
        int b = n - 1;
        while (a >= 0 || b >= 0) {
            int x = a < 0 ? INT_MIN : nums1[a];
            int y = b < 0 ? INT_MIN : nums2[b];
            if (x > y) {
                nums1[r] = x;
                a --;
            } else {
                nums1[r] = y;
                b --;
            }
            r --;
        }
    }
};

int mymain(int argc, char *argv[]) {
    return 0;
}

// === C++ Playground ===
// Execute the snippet with Ctrl-Return
// Remove the snippet completely with its dir and all files M-x `cc-playground-rm`

#include <iostream>

using namespace std;

/*
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (42.44%)
 * Total Accepted:    245.6K
 * Total Submissions: 578.7K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 */
 class Solution {
 public:
   int findKthLargest(vector<int>& nums, int k) {
     int s = 0;
     int t = nums.size() - 1;
     k --;
     default_random_engine gen;
     while (s <= t) {
       uniform_int_distribution<int> ui(s, t);
       int mid = nums[ui(gen)];
       int i = s;
       int j = s;
       int n = t;
       while (j <= n) {
         if (nums[j] > mid) {
           swap(nums[i++], nums[j ++]);
         } else if (nums[j] < mid) {
           swap(nums[j], nums[n--]);
         } else {
           j ++;
         }
       }
       if (k < i) {
         t = i-1;
       } else if (k > n) {
         s = n + 1;
       } else return mid;
     }
     return -1;
   }
 };



int mymain(int argc, char *argv[]) {
    return 0;
}
